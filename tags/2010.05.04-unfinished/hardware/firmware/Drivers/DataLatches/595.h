/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

/* Control the SPI SS0 and SS1 lines, of the data latches */
#define SS0_ENABLE					PORTD |= (1<<PD2)
#define SS0_DISABLE					PORTD &= ~(1<<PD2)
#define SS0_IS_ENABLE				bit_is_set(PORTD, PD2)
#define SS0_IS_DISABLE				bit_is_clear(PORTD, PD2)
#define SS1_ENABLE					PORTD |= (1<<PD3)
#define SS1_DISABLE					PORTD &= ~(1<<PD3)
#define SS1_IS_ENABLE				bit_is_set(PORTD, PD3)
#define SS1_IS_DISABLE				bit_is_clear(PORTD, PD3)


#define LEFT_SIDE_DATA_LATCHES		0
#define RIGHT_SIDE_DATA_LATCHES		1

/* Functions prototypes */
void DataLatches_Init(void);
void DataLatches_Clock(unsigned char SideDataLatches);
