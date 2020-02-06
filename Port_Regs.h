 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Regs.h
 *
 * Description: Header file for Port Module Registers.
 *
 * Author: Ahmed Nasr
 ******************************************************************************/

#ifndef PORT_REGS_H
#define PORT_REGS_H

#include "Std_Types.h"

/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 * const)0x003B)
#define DDRA_REG	(*(volatile uint8 * const)0x003A)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 * const)0x0038)
#define DDRB_REG	(*(volatile uint8 * const)0x0037)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 * const)0x0035)
#define DDRC_REG	(*(volatile uint8 * const)0x0034)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 * const)0x0032)
#define DDRD_REG	(*(volatile uint8 * const)0x0031)

#endif /* PORT_REGS_H */
