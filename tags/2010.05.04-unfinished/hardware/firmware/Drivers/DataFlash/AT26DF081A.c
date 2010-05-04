/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

#include <avr/io.h>
#include <util/delay.h>
#include <Drivers/AT90USB162/SPI.h> /* SPI drivers */

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

/* DataFlash commands */
#define COMMAND_DUMMY						0x00 /* This command do nothing */
#define COMMAND_READ_ARRAY_LOW_FREQUENCY	0x03
#define COMMAND_WRITE_ENABLE				0x06
#define COMMAND_WRITE_DISABLE				0x04
#define COMMAND_READ_STATUS_REGISTER		0x05
#define COMMAND_WRITE_STATUS_REGISTER		0x1h
#define COMMAND_CHIP_ERASE					0x60
#define COMMAND_BYTE_PAGE_PROGRAM			0x02

/* DataFlash status register bit definitions */
#define STATUS_REGISTER_BUSY				1
#define STATUS_REGISTER_ERASE_PROGRAM_ERROR 5


void DataFlash_Init (void)
{
	/* Enable I/Os as outputs for control DataFlash memory */
	DDRB	|=  ((1<<PB5) /* SPI SS2 */
			|   (1<<PB6) /* DataFlash Memory Vcc */
			|   (1<<PB7)); /* DataFlash Memory hold */

	/* Enable Vcc */
	DATAFLASH_VCC_ENABLE;

	/* Disable hold state */
	DATAFLASH_HOLD_ENABLE;
}

/**************************************************************
* This function sends a data byte to DataFlash memory, using 
* SPI BUS. A byte is also received and returned by this function.
*
***************************************************************/
unsigned char _DataFlash_SendData (unsigned char ucData)
{
	SPI_MasterTransmit (ucData);
	
	return (SPI_MasterReceive ());
}

/**************************************************************
* This function erases all memory and holds untill it's done.
* Value 1 is returned if there is some error otherwise is
* returned 0 value.
***************************************************************/
unsigned char DataFlash_EraseAll (void)
{
	/* Put memory on write enable state */
	SS2_DISABLE;
	_DataFlash_SendData (COMMAND_WRITE_ENABLE);
	SS2_ENABLE;

	/* Send Chip Erase command */
	SS2_DISABLE;
	_DataFlash_SendData (COMMAND_CHIP_ERASE);
	SS2_ENABLE;

	/* Wait for all memory be erased */
	SS2_DISABLE;
	_DataFlash_SendData (COMMAND_READ_STATUS_REGISTER);

	while ((_DataFlash_SendData (COMMAND_DUMMY)) & (1 << STATUS_REGISTER_BUSY)) ;
	SS2_ENABLE;

	/* Verify that memory were erased succefull */
	SS2_DISABLE;
	_DataFlash_SendData (COMMAND_READ_STATUS_REGISTER);

	if ((_DataFlash_SendData (COMMAND_DUMMY)) & (1 << STATUS_REGISTER_ERASE_PROGRAM_ERROR))
	{	
		SS2_ENABLE;
		return (1); /* Signal error */
	}

	else
	{
		SS2_ENABLE;
		return (0); /* Erase went sucessefull */
	}
}

/**************************************************************
* This function reads one byte.
* Arguments: Address
* Returns: Byte readed.
*
***************************************************************/
unsigned char DataFlash_ReadByte (unsigned long int uliAddress)
{
	unsigned char ucData;

	/* Send Chip Read array command */
	SS2_DISABLE;
	_DataFlash_SendData (COMMAND_READ_ARRAY_LOW_FREQUENCY);

	/* Send the address */
	_DataFlash_SendData (uliAddress >> 2*8);
	_DataFlash_SendData (uliAddress >> 1*8);
	_DataFlash_SendData ((unsigned char) uliAddress);

	/* Send dummy data to send 8 clock bits, to receive the data byte */
	ucData = _DataFlash_SendData (COMMAND_DUMMY);
	SS2_ENABLE;

	return(ucData);
}

/**************************************************************
* This function writes one byte.
* Arguments: Address and data byte.
* Returns: Value 1 if there is error writing the byte, otherwise
* returns value 0.
***************************************************************/
unsigned char DataFlash_WriteByte (unsigned long int uliAddress, unsigned char ucData)
{
	/* Put memory on write enable state */
	SS2_DISABLE;
	_DataFlash_SendData (COMMAND_WRITE_ENABLE);
	SS2_ENABLE;

	/* Send Byte/Page Program command */
	SS2_DISABLE;
	_DataFlash_SendData (COMMAND_BYTE_PAGE_PROGRAM);

	/* Send the address */
	_DataFlash_SendData (uliAddress >> 2*8);
	_DataFlash_SendData (uliAddress >> 1*8);
	_DataFlash_SendData ((unsigned char) uliAddress);

	/* Send data byte to be written */
	_DataFlash_SendData (ucData);
	SS2_ENABLE;

	/* Verify that byte were written succefull */
	SS2_DISABLE;
	_DataFlash_SendData (COMMAND_READ_STATUS_REGISTER);

	if ((_DataFlash_SendData (COMMAND_DUMMY)) & (1 << STATUS_REGISTER_ERASE_PROGRAM_ERROR))
	{	
		SS2_ENABLE;
		return (1); /* Signal error */
	}

	else
	{
		SS2_ENABLE;
		return (0); /* Write went sucessefull */
	}
}
