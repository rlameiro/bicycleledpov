/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

/* Control the Vcc of DataFlash */
#define DATAFLASH_VCC_ENABLE		PORTB |= (1<<PB6)
#define DATAFLASH_VCC_DISABLE		PORTB &= ~(1<<PB6)
#define DATAFLASH_IS_VCC_ENABLE		bit_is_set(PORTB, PB6)
#define DATAFLASH_IS_VCC_DISABLE	bit_is_clear(PORTB, PB6)

/* Control the SPI SS2 line of the DataFlash */
#define SS2_ENABLE					PORTB |= (1<<PB5)
#define SS2_DISABLE					PORTB &= ~(1<<PB5)
#define SS2_IS_ENABLE				bit_is_set(PORTB, PB5)
#define SS2_IS_DISABLE				bit_is_clear(PORTB, PB5)

/* Control the hold line of the DataFlash */
#define DATAFLASH_HOLD_ENABLE		PORTB |= (1<<PB7)
#define DATAFLASH_HOLD_DISABLE		PORTB &= ~(1<<PB7)
#define DATAFLASH_HOLD_IS_ENABLE	bit_is_set(PORTB, PB7)
#define DATAFLASH_HOLD_IS_DISABLE	bit_is_clear(PORTB, PB7)

/* Functions prototypes */
void DataFlash_Init (void);
//void DataFlash_WriteByte (unsigned char ucData);
//unsigned char DataFlash_ReadByte (void);
