/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

#include <avr/io.h>

void SensorHallEffect_Init(void)
{
	/* Enable I/O as output for sensor hall effect Vcc */
	DDRD |=  (1<<PD1);
}
