/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

#include <../AT90USB162/SPI.h>

/* Instruction Set for the AT25128A */
#define SET_WRITE_ENABLE_LATCHE		0b00000110
#define RESET_WRITE_ENABLE_LATCHE   0b00000100
#define READ_STATUS_REGISTER		0b00000101
#define WRITE_STATUS_REGISTER		0b00000001
#define READ_DATA_FROM_MEMORY_ARRAY 0b00000011
#define WRITE_DATA_TO_MEMORY_ARRAY  0b00000010

/* Defenition bits of Status Register */
#define READY						0b00000001

#define EEPROM_VCC_ENABLE			PORTD |= (1<<PD2)
#define EEPROM_VCC_DISABLE			PORTD &= ~(1<<PD2)
#define EEPROM_SLAVE_SELECT			PORTB &= ~(1<<PB5)
#define EEPROM_SLAVE_DESELECT		PORTB |= (1<<PB5)

/* Functions prototypes*/
unsigned char AT25128A_ReadByte (unsigned short int Address);
void AT25128A_WriteByte(unsigned short int Address, unsigned char DataByte);
