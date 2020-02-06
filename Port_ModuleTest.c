/*
 * Port_ModuleTest.c
 *
 *  Created on: Feb 5, 2020
 *      Author: Ahmed Nasr
 */

#include "Port.h"
#include <util/delay.h>

int main(void)
{
	Port_Init(&Port_Configuration);

	while(1)
	{
		Port_SetPinDirection(PORTCONF_PC2_INDEX, PORT_PIN_OUT);
		_delay_ms(1000);
		Port_RefreshPortDirection();
		_delay_ms(1000);
	}

	return 0;
}
