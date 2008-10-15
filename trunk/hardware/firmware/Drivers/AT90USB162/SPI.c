/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

#include "SPI.h"

void SPI_MasterInit(unsigned char ucDataOrder)
{
	/* Put I/Os as outputs for SPI MOSI and SCK */
	DDRB	|=   ((1<<PB1) /* SPI_SCK */
			|   (1<<PB2)); /* SPI_MOSI */

	PORTB |= (1<<PB0);  /* SPI_SS - this line should be high to SPI works ok */
						/* puting this I/O with internall pull-up */
	
	/* Disable the Power Reduction on Serial Peripheral Interface */
	PRR0 &= ~(1<<PRSPI);
	
	/* Enable SPI, Master, set clock rate fck/128 */
	SPCR |= ((1<<SPE) | (1<<MSTR) | (1<<SPR1) | (1<<SPR0));

	/* Configure the Data Order of first be to be transmited */
	if (ucDataOrder)
		SPCR |= (1<<DORD);
}

void SPI_Disable(void)
{
	/* Disable SPI */
	SPCR &= ~(1<<SPE);
	
	/* Enable the Power Reduction on Serial Peripheral Interface */
	PRR0 |= (1<<PRSPI);
	
	/* Put I/Os as inputs for SPI MOSI and SCK */
	DDRB	&=  ~((1<<PB1) /* SPI_SCK */
			|   (1<<PB2)); /* SPI_MOSI */
}

void SPI_MasterTransmit(unsigned char ucData)
{
	/* Start transmission */
	SPDR = ucData;
	
	/* Wait for transmission complete */
	while(bit_is_clear(SPSR,SPIF))
		;
}

unsigned char SPI_MasterReceive(void)
{
  /* Return Data Register */
  return SPDR;
}
