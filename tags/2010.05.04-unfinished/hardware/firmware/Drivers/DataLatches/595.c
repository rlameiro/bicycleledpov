/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

#include <avr/io.h>
#include "595.h" /* Data latches drivers */

#define LEFT_SIDE_DATA_LATCHES		0
#define RIGHT_SIDE_DATA_LATCHES		1

void DataLatches_Init(void)
{
	/* Enable I/Os as outputs for SPI SS0 and SS1 that are used for */
	/* comunicate with data latches ICs */
	DDRD	|=  ((1<<PD2) /* SPI_SS0 */
			|   (1<<PD3)); /* SPI_SS1 */
}

void DataLatches_Clock(unsigned char SideDataLatches)
{
	switch (SideDataLatches)
	{
		case LEFT_SIDE_DATA_LATCHES:
		SS1_ENABLE;
		SS1_DISABLE;
		break;
		
		case RIGHT_SIDE_DATA_LATCHES:
		SS0_ENABLE;
		SS0_DISABLE;
		break;				

		default:
		break;
	}
}
