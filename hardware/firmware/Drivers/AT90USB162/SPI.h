/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

#include <avr/io.h>

/*******************************************************************************
When the DATA_ORDER_MSB bit is written to one, the LSB of the data word is
transmitted first. When the DATA_ORDER_MSB bit is written to zero, the MSB of the data
word is transmitted first. */
#define DATA_ORDER_MSB	  0
#define DATA_ORDER_LSB	  1

/* Functions prototypes */
void SPI_MasterInit (unsigned char ucDataOrder);
void SPI_Disable (void);
void SPI_MasterTransmit (unsigned char ucData);
unsigned char SPI_MasterReceive (void);
