/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

#include <avr/io.h>

void DataFlash_Init(void)
{
	/* Enable I/Os as outputs for control DataFlash memory */
	DDRB	|=  ((1<<PB5) /* SPI SS2 */
			|   (1<<PB6) /* DataFlash Memory Vcc */
			|   (1<<PB7)); /* DataFlash Memory hold */
}
