#include <avr/io.h>

/*******************************************************************************
When the DORD bit is written to one, the LSB of the data word is
transmitted first. When the DORD bit is written to zero, the MSB of the data
word is transmitted first. */
#define DATA_ORDER_MSB	  0
#define DATA_ORDER_LSB	  1

void SPI_MasterInit(unsigned char DataOrder);
void SPI_Disable(void);
void SPI_MasterTransmit(unsigned char cData);
unsigned char SPI_MasterReceive(void);
