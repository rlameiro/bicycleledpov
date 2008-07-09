/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3      
*/

#include <AT25128A.h>

unsigned char AT25128A_ReadByte (unsigned short int Address)
{
	/* Enable power to EEPROM memory */
	EEPROM_VCC_ENABLE;
	
	/* Initialize the SPI pheripherial */
	SPI_MasterInit (DATA_ORDER_MSB);	
	
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

	/* Disable SPI pheripherial */
	SPI_Disable();
	
	/* Deselect EEPROM on SPI bus */
	EEPROM_SLAVE_DESELECT;
	
	/* Disable power to EEPROM memory */
	EEPROM_VCC_DISABLE;
	
	/* Return the byte readed */
	return (SPI_MasterReceive());
}


void AT25128A_WriteByte(unsigned short int Address, unsigned char DataByte)
{
	/* Enable power to EEPROM memory */
	EEPROM_VCC_ENABLE;

	/* Initialize the SPI pheripherial */
	SPI_MasterInit (DATA_ORDER_MSB);	
	
	/* Select EEPROM on SPI bus */
	EEPROM_SLAVE_SELECT;

	/* Enable write on EEPROM memory */
	SPI_MasterTransmit (SET_WRITE_ENABLE_LATCHE);	

	/* Deselect EEPROM on SPI bus */
	EEPROM_SLAVE_DESELECT;
	
	delay_ms(2);
	
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
	while (!(SPI_MasterReceive() & READY))
		
	/* Disable SPI pheripherial */
	SPI_Disable();
	
	/* Disable power to EEPROM memory */
	EEPROM_VCC_DISABLE;		
	
	return;
}
