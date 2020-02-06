/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Ahmed Nasr
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_ConfigPortPin *Port_ConfiguredPins = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	Port_PinType loopCounter = 0;
	volatile uint8 *DDR_Ptr = NULL_PTR;
	volatile uint8 *Port_Ptr = NULL_PTR;

#if (STD_ON == PORT_DEV_ERROR_DETECT)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_INIT_SID,
						PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Port_ConfiguredPins = ConfigPtr->PortPin;

		/* for each configured pin */
		for (loopCounter=0; loopCounter<PORT_TOTAL_NUMBER_OF_PINS; loopCounter++)
		{
			/* Check if the port pin's mode is configured as DIO pin mode */
			if (Port_ConfiguredPins[loopCounter].PortPinInitialMode == PORT_PIN_MODE_DIO)
			{
				/* Get the port pin's port and pin addresses */
				switch (Port_ConfiguredPins[loopCounter].PortId)
				{
				case PORT_PORTA_INDEX:	DDR_Ptr = &DDRA_REG;
										Port_Ptr = &PORTA_REG;
										break;

				case PORT_PORTB_INDEX:	DDR_Ptr = &DDRB_REG;
										Port_Ptr = &PORTB_REG;
										break;

				case PORT_PORTC_INDEX:	DDR_Ptr = &DDRC_REG;
										Port_Ptr = &PORTC_REG;
										break;

				case PORT_PORTD_INDEX:	DDR_Ptr = &DDRD_REG;
										Port_Ptr = &PORTD_REG;
										break;

				default:				break;
				}

				/* Check if the port pin's direction is configured as input */
				if (Port_ConfiguredPins[loopCounter].PortPinDirection == PORT_PIN_IN)
				{
					CLEAR_BIT(*DDR_Ptr, Port_ConfiguredPins[loopCounter].PortPinId);

					/*
					 * For input port pins only
					 * Check if the port pin's internal pull up is configured as not active
					 */
					if (Port_ConfiguredPins[loopCounter].PortPinActivatePullUp == STD_OFF)
					{
						CLEAR_BIT(*Port_Ptr, Port_ConfiguredPins[loopCounter].PortPinId);
					}
					/* Check if the port pin's internal pull up is configured as active */
					else if (Port_ConfiguredPins[loopCounter].PortPinActivatePullUp == STD_ON)
					{
						SET_BIT(*Port_Ptr, Port_ConfiguredPins[loopCounter].PortPinId);
					}
				}
				/* Check if the port pin's direction is configured as output */
				else if (Port_ConfiguredPins[loopCounter].PortPinDirection == PORT_PIN_OUT)
				{
					SET_BIT(*DDR_Ptr, Port_ConfiguredPins[loopCounter].PortPinId);

					/*
					 * For output port pins only
					 * Check if the port pin's initial value is configured as std low
					 */
					if (Port_ConfiguredPins[loopCounter].PortPinLevelValue == STD_LOW)
					{
						CLEAR_BIT(*Port_Ptr, Port_ConfiguredPins[loopCounter].PortPinId);
					}
					/* Check if the port pin's initial value is configured as std high */
					else if (Port_ConfiguredPins[loopCounter].PortPinLevelValue == STD_HIGH)
					{
						SET_BIT(*Port_Ptr, Port_ConfiguredPins[loopCounter].PortPinId);
					}
				}
			}
			else
			{
				/* No action required */
			}
		}

		/* The port is initialized successfully */
		Port_Status = PORT_INITIALIZED;
	}
}

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
* 				   Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction
************************************************************************************/
#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
	volatile uint8 *DDR_Ptr = NULL_PTR;
	boolean error = FALSE;

#if (STD_ON == PORT_DEV_ERROR_DETECT)
	/* Check if the port driver is already initialized or not */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report error in case of calling this function and the port driver is not initialized */
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_SET_PIN_DIRECTION_SID,
						PORT_E_UNINIT);

		error = TRUE;
	}
	else
	{
		/* No action required */
	}

	/* Check for the validation of the Pin number, (i.e. PORTCONF_PA0_INDEX) */
	if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
	{
		/* Report error in case of calling this function and passing a wrong pin number */
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_SET_PIN_DIRECTION_SID,
						PORT_E_PARAM_PIN);

		error = TRUE;
	}
	else
	{
		/* No action required */
	}

	/* Check for the availability of changing pin direction in runtime */
	if (STD_OFF == Port_ConfiguredPins[Pin].PortPinDirectionChangeable)
	{
		/* Report error in case of calling this function and the pin is configured as direction unchangeable */
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_SET_PIN_DIRECTION_SID,
						PORT_E_DIRECTION_UNCHANGEABLE);

		error = TRUE;
	}
	else
	{
		/* No action required */
	}
#endif

	/* There are no errors */
	if (FALSE == error)
	{
		/* Set the DDR pointer to the pin number's corresponding port */
		switch (Port_ConfiguredPins[Pin].PortId)
		{
		case PORT_PORTA_INDEX:	DDR_Ptr = &DDRA_REG;
								break;

		case PORT_PORTB_INDEX:	DDR_Ptr = &DDRB_REG;
								break;

		case PORT_PORTC_INDEX:	DDR_Ptr = &DDRC_REG;
								break;

		case PORT_PORTD_INDEX:	DDR_Ptr = &DDRD_REG;
								break;

		default:				break;
		}

		/* The direction of the port pin is configured as input */
		if (PORT_PIN_IN == Direction)
		{
			/* Write logic low */
			CLEAR_BIT(*DDR_Ptr, Port_ConfiguredPins[Pin].PortPinId);
		}
		/* The direction of the port pin is configured as output */
		else if (PORT_PIN_OUT == Direction)
		{
			/* Write logic high */
			SET_BIT(*DDR_Ptr, Port_ConfiguredPins[Pin].PortPinId);
		}
		else
		{
			/* No action required */
		}
	}
	else
	{
		/* No action required */
	}
}
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction
************************************************************************************/
void Port_RefreshPortDirection(void)
{
	Port_PinType loopCounter = 0;
	volatile uint8 *DDR_Ptr = NULL_PTR;

#if (STD_ON == PORT_DEV_ERROR_DETECT)
	/* Check if the port driver is already initialized or not */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report error in case of calling this function and the port driver is not initialized */
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_REFRESH_PORT_DIRECTION_SID,
						PORT_E_UNINIT);
	}
	else
#endif
	{
		/* For each port pin */
		for (loopCounter=0; loopCounter<PORT_TOTAL_NUMBER_OF_PINS; loopCounter++)
		{
			/* Check for the changeability of port pin's direction */
			if (STD_ON == Port_ConfiguredPins[loopCounter].PortPinDirectionChangeable)
			{
				/* Set the DDR pointer to the pin number's corresponding port */
				switch (Port_ConfiguredPins[loopCounter].PortId)
				{
				case PORT_PORTA_INDEX:	DDR_Ptr = &DDRA_REG;
										break;

				case PORT_PORTB_INDEX:	DDR_Ptr = &DDRB_REG;
										break;

				case PORT_PORTC_INDEX:	DDR_Ptr = &DDRC_REG;
										break;

				case PORT_PORTD_INDEX:	DDR_Ptr = &DDRD_REG;
										break;

				default:				break;
				}

				/* In case of the port pin's direction is configured as input */
				if (PORT_PIN_IN == Port_ConfiguredPins[loopCounter].PortPinDirection)
				{
					/* Write logic low */
					CLEAR_BIT(*DDR_Ptr, Port_ConfiguredPins[loopCounter].PortPinId);
				}
				/* In case of the port pin's direction is configured as output */
				else if (PORT_PIN_OUT == Port_ConfiguredPins[loopCounter].PortPinDirection)
				{
					/* Write logic high */
					SET_BIT(*DDR_Ptr, Port_ConfiguredPins[loopCounter].PortPinId);
				}
				else
				{
					/* No action required */
				}
			}
			else
			{
				/* No action required */
			}
		}
	}
}

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module
* Return value: None
* Description: Returns the version information of this module
************************************************************************************/
#if (STD_ON == PORT_VERSION_INFO_API)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_GET_VERSION_INFO_SID,
						PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
* 				   Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode
************************************************************************************/
#if (STD_ON == PORT_SET_PIN_MODE_API)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	boolean error = FALSE;

#if (STD_ON == PORT_DEV_ERROR_DETECT)
	/* Check if the port driver is already initialized or not */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report error in case of calling this function and the port driver is not initialized */
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_SET_PIN_MODE_SID,
						PORT_E_UNINIT);

		error = TRUE;
	}
	else
	{
		/* No action required */
	}

	/* Check for the validation of the Pin number, (i.e. PORTCONF_PA0_INDEX) */
	if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
	{
		/* Report error in case of calling this function and passing a wrong pin number */
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_SET_PIN_MODE_SID,
						PORT_E_PARAM_PIN);

		error = TRUE;
	}
	else
	{
		/* No action required */
	}

	/* Check for the availability of changing pin mode in runtime */
	if (STD_OFF == Port_ConfiguredPins[Pin].PortPinModeChangeable)
	{
		/* Report error in case of calling this function and the pin is configured as mode unchangeable */
		Det_ReportError(PORT_MODULE_ID,
						PORT_INSTANCE_ID,
						PORT_SET_PIN_MODE_SID,
						PORT_E_MODE_UNCHANGEABLE);

		error = TRUE;
	}
	else
	{
		/* No action required */
	}
#endif

	/* There are no errors */
	if (FALSE == error)
	{
		/* Hardware limitation - No action required */
	}
	else
	{
		/* No action required */
	}
}
#endif
