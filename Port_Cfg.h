 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for Port Module.
 *
 * Author: Ahmed Nasr
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

#include "Port.h"
/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-processor switch to enable / disable the use of the function Port_SetPinDirection */
#define PORT_SET_PIN_DIRECTION_API			 (STD_ON)

/* Pre-processor switch to enable / disable the use of the function Port_SetPinMode */
#define PORT_SET_PIN_MODE_API				 (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define PORT_VERSION_INFO_API				 (STD_ON)

/* Port Indexes */
#define PORT_PORTA_INDEX				    	0
#define PORT_PORTB_INDEX						1
#define PORT_PORTC_INDEX						2
#define PORT_PORTD_INDEX						3

/* Channel Index in the array of structures in Port_PBcfg.c */
#define PORTCONF_PA0_INDEX		    	 		(uint8)0
#define PORTCONF_PA1_INDEX		    	 		(uint8)1
#define PORTCONF_PA2_INDEX		    	 		(uint8)2
#define PORTCONF_PA3_INDEX		    	 		(uint8)3
#define PORTCONF_PA4_INDEX		    	 		(uint8)4
#define PORTCONF_PA5_INDEX		    	 		(uint8)5
#define PORTCONF_PA6_INDEX		    	 		(uint8)6
#define PORTCONF_PA7_INDEX		    	 		(uint8)7

#define PORTCONF_PB0_INDEX				 		(uint8)8
#define PORTCONF_PB1_INDEX				 		(uint8)9
#define PORTCONF_PB2_INDEX				 		(uint8)10
#define PORTCONF_PB3_INDEX				 		(uint8)11
#define PORTCONF_PB4_INDEX				 		(uint8)12
#define PORTCONF_PB5_INDEX				 		(uint8)13
#define PORTCONF_PB6_INDEX				 		(uint8)14
#define PORTCONF_PB7_INDEX				 		(uint8)15

#define PORTCONF_PC0_INDEX     	 		 		(uint8)16
#define PORTCONF_PC1_INDEX     	 		 		(uint8)17
#define PORTCONF_PC2_INDEX     	 		 		(uint8)18
#define PORTCONF_PC3_INDEX     	 		 		(uint8)19
#define PORTCONF_PC4_INDEX     	 		 		(uint8)20
#define PORTCONF_PC5_INDEX     	 		 		(uint8)21
#define PORTCONF_PC6_INDEX     	 		 		(uint8)22
#define PORTCONF_PC7_INDEX     	 		 		(uint8)23

#define PORTCONF_PD0_INDEX				 		(uint8)24
#define PORTCONF_PD1_INDEX				 		(uint8)25
#define PORTCONF_PD2_INDEX				 		(uint8)26
#define PORTCONF_PD3_INDEX				 		(uint8)27
#define PORTCONF_PD4_INDEX				 		(uint8)28
#define PORTCONF_PD5_INDEX				 		(uint8)29
#define PORTCONF_PD6_INDEX				 		(uint8)30
#define PORTCONF_PD7_INDEX				 		(uint8)31

/* PORT Configured Port ID */
#define PORTCONF_PA0_PORT_NUM            		(Port_PortType)PORT_PORTA_INDEX /* PORTA */
#define PORTCONF_PA1_PORT_NUM            		(Port_PortType)PORT_PORTA_INDEX /* PORTA */
#define PORTCONF_PA2_PORT_NUM            		(Port_PortType)PORT_PORTA_INDEX /* PORTA */
#define PORTCONF_PA3_PORT_NUM            		(Port_PortType)PORT_PORTA_INDEX /* PORTA */
#define PORTCONF_PA4_PORT_NUM            		(Port_PortType)PORT_PORTA_INDEX /* PORTA */
#define PORTCONF_PA5_PORT_NUM            		(Port_PortType)PORT_PORTA_INDEX /* PORTA */
#define PORTCONF_PA6_PORT_NUM            		(Port_PortType)PORT_PORTA_INDEX /* PORTA */
#define PORTCONF_PA7_PORT_NUM            		(Port_PortType)PORT_PORTA_INDEX /* PORTA */

#define PORTCONF_PB0_PORT_NUM            		(Port_PortType)PORT_PORTB_INDEX /* PORTB */
#define PORTCONF_PB1_PORT_NUM            		(Port_PortType)PORT_PORTB_INDEX /* PORTB */
#define PORTCONF_PB2_PORT_NUM            		(Port_PortType)PORT_PORTB_INDEX /* PORTB */
#define PORTCONF_PB3_PORT_NUM            		(Port_PortType)PORT_PORTB_INDEX /* PORTB */
#define PORTCONF_PB4_PORT_NUM            		(Port_PortType)PORT_PORTB_INDEX /* PORTB */
#define PORTCONF_PB5_PORT_NUM            		(Port_PortType)PORT_PORTB_INDEX /* PORTB */
#define PORTCONF_PB6_PORT_NUM            		(Port_PortType)PORT_PORTB_INDEX /* PORTB */
#define PORTCONF_PB7_PORT_NUM            		(Port_PortType)PORT_PORTB_INDEX /* PORTB */

#define PORTCONF_PC0_PORT_NUM            		(Port_PortType)PORT_PORTC_INDEX /* PORTC */
#define PORTCONF_PC1_PORT_NUM            		(Port_PortType)PORT_PORTC_INDEX /* PORTC */
#define PORTCONF_PC2_PORT_NUM            		(Port_PortType)PORT_PORTC_INDEX /* PORTC */
#define PORTCONF_PC3_PORT_NUM            		(Port_PortType)PORT_PORTC_INDEX /* PORTC */
#define PORTCONF_PC4_PORT_NUM            		(Port_PortType)PORT_PORTC_INDEX /* PORTC */
#define PORTCONF_PC5_PORT_NUM            		(Port_PortType)PORT_PORTC_INDEX /* PORTC */
#define PORTCONF_PC6_PORT_NUM            		(Port_PortType)PORT_PORTC_INDEX /* PORTC */
#define PORTCONF_PC7_PORT_NUM            		(Port_PortType)PORT_PORTC_INDEX /* PORTC */

#define PORTCONF_PD0_PORT_NUM            		(Port_PortType)PORT_PORTD_INDEX /* PORTD */
#define PORTCONF_PD1_PORT_NUM            		(Port_PortType)PORT_PORTD_INDEX /* PORTD */
#define PORTCONF_PD2_PORT_NUM            		(Port_PortType)PORT_PORTD_INDEX /* PORTD */
#define PORTCONF_PD3_PORT_NUM            		(Port_PortType)PORT_PORTD_INDEX /* PORTD */
#define PORTCONF_PD4_PORT_NUM            		(Port_PortType)PORT_PORTD_INDEX /* PORTD */
#define PORTCONF_PD5_PORT_NUM            		(Port_PortType)PORT_PORTD_INDEX /* PORTD */
#define PORTCONF_PD6_PORT_NUM            		(Port_PortType)PORT_PORTD_INDEX /* PORTD */
#define PORTCONF_PD7_PORT_NUM            		(Port_PortType)PORT_PORTD_INDEX /* PORTD */

/* PORT Configured Channel ID */
#define PORTCONF_PA0_PIN_NUM            		(Port_PinType)0 /* Pin 0 in PORTA */
#define PORTCONF_PA1_PIN_NUM            		(Port_PinType)1 /* Pin 1 in PORTA */
#define PORTCONF_PA2_PIN_NUM            		(Port_PinType)2 /* Pin 2 in PORTA */
#define PORTCONF_PA3_PIN_NUM            		(Port_PinType)3 /* Pin 3 in PORTA */
#define PORTCONF_PA4_PIN_NUM            		(Port_PinType)4 /* Pin 4 in PORTA */
#define PORTCONF_PA5_PIN_NUM            		(Port_PinType)5 /* Pin 5 in PORTA */
#define PORTCONF_PA6_PIN_NUM            		(Port_PinType)6 /* Pin 6 in PORTA */
#define PORTCONF_PA7_PIN_NUM            		(Port_PinType)7 /* Pin 7 in PORTA */

#define PORTCONF_PB0_PIN_NUM            		(Port_PinType)0 /* Pin 0 in PORTB */
#define PORTCONF_PB1_PIN_NUM            		(Port_PinType)1 /* Pin 1 in PORTB */
#define PORTCONF_PB2_PIN_NUM            		(Port_PinType)2 /* Pin 2 in PORTB */
#define PORTCONF_PB3_PIN_NUM            		(Port_PinType)3 /* Pin 3 in PORTB */
#define PORTCONF_PB4_PIN_NUM            		(Port_PinType)4 /* Pin 4 in PORTB */
#define PORTCONF_PB5_PIN_NUM            		(Port_PinType)5 /* Pin 5 in PORTB */
#define PORTCONF_PB6_PIN_NUM            		(Port_PinType)6 /* Pin 6 in PORTB */
#define PORTCONF_PB7_PIN_NUM            		(Port_PinType)7 /* Pin 7 in PORTB */

#define PORTCONF_PC0_PIN_NUM            		(Port_PinType)0 /* Pin 0 in PORTC */
#define PORTCONF_PC1_PIN_NUM            		(Port_PinType)1 /* Pin 1 in PORTC */
#define PORTCONF_PC2_PIN_NUM            		(Port_PinType)2 /* Pin 2 in PORTC */
#define PORTCONF_PC3_PIN_NUM            		(Port_PinType)3 /* Pin 3 in PORTC */
#define PORTCONF_PC4_PIN_NUM            		(Port_PinType)4 /* Pin 4 in PORTC */
#define PORTCONF_PC5_PIN_NUM            		(Port_PinType)5 /* Pin 5 in PORTC */
#define PORTCONF_PC6_PIN_NUM            		(Port_PinType)6 /* Pin 6 in PORTC */
#define PORTCONF_PC7_PIN_NUM            		(Port_PinType)7 /* Pin 7 in PORTC */

#define PORTCONF_PD0_PIN_NUM            		(Port_PinType)0 /* Pin 0 in PORTD */
#define PORTCONF_PD1_PIN_NUM            		(Port_PinType)1 /* Pin 1 in PORTD */
#define PORTCONF_PD2_PIN_NUM            		(Port_PinType)2 /* Pin 2 in PORTD */
#define PORTCONF_PD3_PIN_NUM            		(Port_PinType)3 /* Pin 3 in PORTD */
#define PORTCONF_PD4_PIN_NUM            		(Port_PinType)4 /* Pin 4 in PORTD */
#define PORTCONF_PD5_PIN_NUM            		(Port_PinType)5 /* Pin 5 in PORTD */
#define PORTCONF_PD6_PIN_NUM            		(Port_PinType)6 /* Pin 6 in PORTD */
#define PORTCONF_PD7_PIN_NUM            		(Port_PinType)7 /* Pin 7 in PORTD */

/* PORT Configured Initial Modes */
#define PORTCONF_PA0_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PA1_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PA2_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PA3_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PA4_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PA5_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PA6_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PA7_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO

#define PORTCONF_PB0_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PB1_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PB2_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PB3_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PB4_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PB5_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PB6_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PB7_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO

#define PORTCONF_PC0_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PC1_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PC2_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PC3_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PC4_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PC5_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PC6_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PC7_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO

#define PORTCONF_PD0_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PD1_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PD2_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PD3_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PD4_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PD5_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PD6_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO
#define PORTCONF_PD7_INITIAL_MODE		 		(Port_PinModeType)PORT_PIN_MODE_DIO

/* PORT Configured Initial Directions */
#define PORTCONF_PA0_INITIAL_DIRECTION	 		(PORT_PIN_OUT)
#define PORTCONF_PA1_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PA2_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PA3_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PA4_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PA5_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PA6_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PA7_INITIAL_DIRECTION	 		(PORT_PIN_OUT)

#define PORTCONF_PB0_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PB1_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PB2_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PB3_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PB4_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PB5_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PB6_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PB7_INITIAL_DIRECTION	 		(PORT_PIN_IN)

#define PORTCONF_PC0_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PC1_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PC2_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PC3_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PC4_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PC5_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PC6_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PC7_INITIAL_DIRECTION	 		(PORT_PIN_IN)

#define PORTCONF_PD0_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PD1_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PD2_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PD3_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PD4_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PD5_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PD6_INITIAL_DIRECTION	 		(PORT_PIN_IN)
#define PORTCONF_PD7_INITIAL_DIRECTION	 		(PORT_PIN_IN)

/* PORT Configured Initial Levels */
#define PORTCONF_PA0_INITIAL_LEVEL	 			(STD_HIGH)
#define PORTCONF_PA1_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PA2_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PA3_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PA4_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PA5_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PA6_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PA7_INITIAL_LEVEL	 			(STD_LOW)

#define PORTCONF_PB0_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PB1_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PB2_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PB3_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PB4_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PB5_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PB6_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PB7_INITIAL_LEVEL	 			(STD_LOW)

#define PORTCONF_PC0_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PC1_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PC2_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PC3_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PC4_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PC5_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PC6_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PC7_INITIAL_LEVEL	 			(STD_LOW)

#define PORTCONF_PD0_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PD1_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PD2_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PD3_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PD4_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PD5_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PD6_INITIAL_LEVEL	 			(STD_LOW)
#define PORTCONF_PD7_INITIAL_LEVEL	 			(STD_LOW)

/* PORT Configured Direction Changeable (STD_ON, STD_OFF) */
#define PORTCONF_PA0_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PA1_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PA2_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PA3_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PA4_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PA5_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PA6_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PA7_DIRECTION_CHANGEABLE	 	(STD_ON)

#define PORTCONF_PB0_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PB1_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PB2_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PB3_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PB4_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PB5_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PB6_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PB7_DIRECTION_CHANGEABLE	 	(STD_ON)

#define PORTCONF_PC0_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PC1_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PC2_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PC3_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PC4_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PC5_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PC6_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PC7_DIRECTION_CHANGEABLE	 	(STD_ON)

#define PORTCONF_PD0_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PD1_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PD2_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PD3_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PD4_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PD5_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PD6_DIRECTION_CHANGEABLE	 	(STD_ON)
#define PORTCONF_PD7_DIRECTION_CHANGEABLE	 	(STD_ON)

/* PORT Configured Mode Changeable (STD_ON, STD_OFF) */
#define PORTCONF_PA0_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PA1_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PA2_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PA3_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PA4_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PA5_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PA6_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PA7_MODE_CHANGEABLE	 		(STD_ON)

#define PORTCONF_PB0_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PB1_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PB2_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PB3_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PB4_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PB5_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PB6_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PB7_MODE_CHANGEABLE	 		(STD_ON)

#define PORTCONF_PC0_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PC1_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PC2_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PC3_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PC4_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PC5_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PC6_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PC7_MODE_CHANGEABLE	 		(STD_ON)

#define PORTCONF_PD0_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PD1_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PD2_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PD3_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PD4_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PD5_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PD6_MODE_CHANGEABLE	 		(STD_ON)
#define PORTCONF_PD7_MODE_CHANGEABLE	 		(STD_ON)

/* PORT Configured Internal Pull-up */
#define PORTCONF_PA0_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PA1_ACTIVATE_PULLUP			(STD_ON)
#define PORTCONF_PA2_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PA3_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PA4_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PA5_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PA6_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PA7_ACTIVATE_PULLUP			(STD_OFF)

#define PORTCONF_PB0_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PB1_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PB2_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PB3_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PB4_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PB5_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PB6_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PB7_ACTIVATE_PULLUP			(STD_OFF)

#define PORTCONF_PC0_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PC1_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PC2_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PC3_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PC4_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PC5_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PC6_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PC7_ACTIVATE_PULLUP			(STD_OFF)

#define PORTCONF_PD0_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PD1_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PD2_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PD3_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PD4_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PD5_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PD6_ACTIVATE_PULLUP			(STD_OFF)
#define PORTCONF_PD7_ACTIVATE_PULLUP			(STD_OFF)

#endif /* PORT_CFG_H */
