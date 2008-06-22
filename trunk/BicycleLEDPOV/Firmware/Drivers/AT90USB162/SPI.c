/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

#include "SPI.h"

void SPI_MasterInit(unsigned char DataOrder)
{
	/* Disable the Power Reduction on Serial Peripheral Interface */
	PRR0 &= ~(1<<PRSPI);
	
	/* Set MOSI, SCK output and SS pins of EEPROM and data lacthes as outputs */
	DDRB |= ((1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB4));
	/* Enable SPI, Master, set clock rate fck/2 */
	SPCR |= ((1<<SPE) | (1<<MSTR) | (1<<SPI2X));

	/* Configure the Data Order of first be to be transmited */
	if (DataOrder)
		SPCR |= (1<<DORD);
}

void SPI_Disable(void)
{
	/* Disable SPI */
	SPCR &= ~(1<<SPE);
	
	/* Enable the Power Reduction on Serial Peripheral Interface */
	PRR0 |= (1<<PRSPI);
}

void SPI_MasterTransmit(unsigned char cData)
{
  /* Start transmission */
  SPDR = cData;
  /* Wait for transmission complete */
  while(bit_is_clear(SPSR,SPIF))
    ;
}

unsigned char SPI_MasterReceive(void)
{
  /* Return Data Register */
  return SPDR;
}
