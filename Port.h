 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Ahmed Nasr
 ******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/* Id for the company in the AUTOSAR
 * for example Ahmed Nasr's ID = 500 :) */
#define PORT_VENDOR_ID    (500U)

/* PORT Module Id */
#define PORT_MODULE_ID    (124U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Number of the total port pins */
#define PORT_TOTAL_NUMBER_OF_PINS		(Port_PinType)32

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and PORT Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* PORT Pre-Compile Configuration Header file */
#include "PORT_Cfg.h"

/* AUTOSAR Version checking between PORT_Cfg.h and PORT.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PORT_Cfg.h does not match the expected version"
#endif

/* Software Version checking between PORT_Cfg.h and PORT.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PORT_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT init */
#define PORT_INIT_SID						(uint8)0x00

/* Service ID for PORT set pin direction */
#define PORT_SET_PIN_DIRECTION_SID			(uint8)0x01

/* Service ID for PORT refresh port direction */
#define PORT_REFRESH_PORT_DIRECTION_SID		(uint8)0x02

/* Service ID for PORT get version info */
#define PORT_GET_VERSION_INFO_SID			(uint8)0x03

/* Service ID for PORT set pin mode */
#define PORT_SET_PIN_MODE_SID				(uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN 				(uint8)0x0A

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE	(uint8)0x0B

/* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG				(uint8)0x0C

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE		(uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE		(uint8)0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT					(uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER			(uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Data type for the symbolic name of a port */
typedef uint8 Port_PortType;

/* Data type for the symbolic name of a port pin */
typedef uint8 Port_PinType;

/* Possible directions of a port pin */
typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
} Port_PinDirectionType;

/* Enumeration for pin modes */
enum
{
	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_CAN,
	PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,
	PORT_PIN_MODE_DIO_WDG,
	PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,
	PORT_PIN_MODE_LIN,
	PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,
	PORT_PIN_MODE_SPI
};

typedef uint8 Port_InitLevelType;

/* Different port pin modes */
typedef uint8 Port_PinModeType;

/* Type of the external data structure containing the initialization data for this module */
typedef struct
{
	/* Port Id of the port pin */
	Port_PortType PortId;

	/* Pin Id of the port pin */
	Port_PinType PortPinId;

	/* Port pin mode from mode list for use with Port_Init function, (PIN_MODE_DIO, PIN_MODE_ADC, PIN_MODE_SPI …) */
	Port_PinModeType PortPinInitialMode;

	/* The initial direction of the pin, (PORT_PIN_IN, PORT_PIN_OUT) */
	Port_PinDirectionType PortPinDirection;

	/* The initial level of the pin, (STD_HIGH, STD_LOW) */
	Port_InitLevelType PortPinLevelValue;

	/* Parameter to indicate if the direction is changeable on a port pin during runtime, (STD_ON, STD_OFF) */
	boolean PortPinDirectionChangeable:1;

	/* Parameter to indicate if the mode is changeable on a port pin during runtime, (STD_ON, STD_OFF) */
	boolean PortPinModeChangeable:1;

	/* Activation of internal pull-ups, (STD_ON, STD_OFF) */
	boolean PortPinActivatePullUp:1;
} Port_ConfigPortPin;

/* Data Structure required for initializing the Port Driver */
typedef struct
{
	Port_ConfigPortPin PortPin[PORT_TOTAL_NUMBER_OF_PINS];
} Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Initializes the Port Driver module */
void Port_Init(const Port_ConfigType* ConfigPtr);

/* Sets the port pin direction */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);

/* Refreshes port direction */
void Port_RefreshPortDirection(void);

/* Returns the version information of this module */
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);

/* Sets the port pin mode */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H_ */
