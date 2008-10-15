/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

/* Get status of data output line of sensor hall effect */
#define BUTTON_IS_SET			bit_is_clear(PIND, PD7)
#define BUTTON_IS_CLEAR			bit_is_set(PIND, PD7)

#define BUTTON_INIT DDRD &= ~(1<<PD7); /* Enable I/O as input */
