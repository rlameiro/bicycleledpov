/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3      
*/

#include <avr/io.h>
#include <Drivers/AT90USB162/SPI.h> /* SPI drivers */

/* Instruction Set for the AT25128A */
#define SET_WRITE_ENABLE_LATCHE			0b00000110
#define RESET_WRITE_ENABLE_LATCHE   	0b00000100
#define READ_STATUS_REGISTER        	0b00000101
#define WRITE_STATUS_REGISTER       	0b00000001
#define READ_DATA_FROM_MEMORY_ARRAY 	0b00000011
#define WRITE_DATA_TO_MEMORY_ARRAY  	0b00000010

/* Defenition bits of Status Register */
#define READY                           0b00000001

#define EEPROM_VCC_ENABLE               PORTB |= (1<<PB6)
#define EEPROM_VCC_DISABLE              PORTB &= ~(1<<PB6)
#define EEPROM_SLAVE_SELECT             PORTB &= ~(1<<PB5)
#define EEPROM_SLAVE_DESELECT           PORTB |= (1<<PB5)
#define EEPROM_HOLD_ENABLE				PORTB &= ~(1<<PB7)
#define EEPROM_HOLD_DISABLE				PORTB |= (1<<PB7)

void EEPROM_Init (void)
{
	/* Enable I/Os as outputs for control EEPROM memory */
	DDRB	|=  ((1<<PB5) /* SPI SS2 */
			|   (1<<PB6) /* EEPROM Memory Vcc */
			|   (1<<PB7)); /* EEPROM Memory hold */

	/* Enable Vcc */
	EEPROM_VCC_ENABLE;

	/* Disable hold state */
	EEPROM_HOLD_ENABLE;
	
	/* Send one byte just to init ok the EEPROM -- tested on practice */
	/* Without this, the first command will not work, be it read or write */
    EEPROM_SLAVE_SELECT;
    SPI_MasterTransmit (0);
    EEPROM_SLAVE_DESELECT;
}

unsigned char EEPROM_ReadByte (unsigned short int Address)
{
    /* Select EEPROM on SPI bus */
    EEPROM_SLAVE_SELECT;
        
    /* Send to EEPROM the intruction to read a memory array */ 
    SPI_MasterTransmit (READ_DATA_FROM_MEMORY_ARRAY);
        
    /* Send the most significant bits */
    SPI_MasterTransmit ((unsigned char) (Address>>8));

    /* Send the least significant bits */
    SPI_MasterTransmit ((unsigned char) (Address));
        
    /* Send a "not care" data byte to receive the readed byte */
    SPI_MasterTransmit (0);

    /* Deselect EEPROM on SPI bus */
    EEPROM_SLAVE_DESELECT;

    /* Return the byte readed */
    return (SPI_MasterReceive());
}


void EEPROM_WriteByte(unsigned short int Address, unsigned char DataByte)
{
    /* Select EEPROM on SPI bus */
    EEPROM_SLAVE_SELECT;

    /* Enable write on EEPROM memory */
    SPI_MasterTransmit (SET_WRITE_ENABLE_LATCHE);   

    /* Deselect EEPROM on SPI bus */
    EEPROM_SLAVE_DESELECT;

    /* Select EEPROM on SPI bus */
    EEPROM_SLAVE_SELECT;
        
	/* Send to EEPROM the intruction to write a memory array */ 
	SPI_MasterTransmit (WRITE_DATA_TO_MEMORY_ARRAY);
        
	/* Send the most significant bits */
	SPI_MasterTransmit ((unsigned char) (Address>>8));

	/* Send the least significant bits */
	SPI_MasterTransmit ((unsigned char) (Address));
        
	/* Send the byte to be written */
	SPI_MasterTransmit (DataByte);
        
	/* Deselect EEPROM on SPI bus */
	EEPROM_SLAVE_DESELECT;
       
	/* Wait for EEPROM finnish the write cycle */
	do
	{
		/* Select EEPROM on SPI bus */
		EEPROM_SLAVE_SELECT;
                
		/* Send command to read Status Register of EEPROM memory */
		SPI_MasterTransmit (READ_STATUS_REGISTER);
                
		/* Send a "not care" data byte to receive the readed byte */
		SPI_MasterTransmit (0);
                
		/* Deselect EEPROM on SPI bus */
		EEPROM_SLAVE_DESELECT;
	}
	while ((SPI_MasterReceive() & READY));
}
