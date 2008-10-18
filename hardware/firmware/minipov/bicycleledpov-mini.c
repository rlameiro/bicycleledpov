/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

/*
             MyUSB Library
     Copyright (C) Dean Camera, 2008.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com

 Released under the LGPL Licence, Version 3
*/

/*
	Communications Device Class demonstration application.
	This gives a simple reference application for implementing
	a USB to Serial converter. Sent and recieved data on the
	serial port is communicated to the USB host.
	
	Before running, you will need to install the INF file that
	is located in the CDC project directory. This will enable
	Windows to use its inbuilt CDC drivers, negating the need
	for special Windows drivers for the device. To install,
	right-click the .INF file and choose the Install option.
*/

/*
	USB Mode:           Device
	USB Class:          Communications Device Class (CDC)
	USB Subclass:       Abstract Control Model (ACM)
	Relevant Standards: USBIF CDC Class Standard
	Usable Speeds:      Full Speed Mode
*/

#include "bicycleledpov-mini.h"

/* Scheduler Task List */
TASK_LIST
{
	{ Task: BicycleLEDPOV_Mini  , TaskStatus: TASK_RUN },
};

/* Globals: */
const static unsigned char image[] = {
	0b00000000, 0b00000000,
	0b00000000, 0b00001110,
	0b00000000, 0b11111111,
	0b00000000, 0b00000000,
	0b00000000, 0b11110011,
	0b00000000, 0b11011011,
	0b00000000, 0b11001111,
	0b00000000, 0b00000000,
	0b00000000, 0b11010011,
	0b00000000, 0b11010011,
	0b00000000, 0b01111110,
	0b00000000, 0b00000000,
	0b00000000, 0b00000000,
	0b00000000, 0b00000000,
	0b00000000, 0b00000000,
	0b00000000, 0b00000000,
	0b00000000, 0b00000000,
	0b00000000, 0b00000000,
	0b00000000, 0b00000000,
	0b00000000, 0b00000000,
};
ISR(TIMER1_COMPA_vect, ISR_BLOCK)
{
	/* Scheduler test - increment scheduler tick counter once each millisecond */
	Scheduler_TickCounter++;
}
		
int main(void)
{
	/* Disable watchdog if enabled by bootloader/fuses */
	MCUSR &= ~(1 << WDRF);
	wdt_disable();

	/* Disable Clock Division */
	SetSystemClockPrescaler(0);
	/* Hardware Initialization */
	Hardware_Init();

	/* Initialize Scheduler so that it can be used */
	Scheduler_Init();

	/* Scheduling - routine never returns, so put this last in the main function */
	Scheduler_Start();
}


TASK(BicycleLEDPOV_Mini)
{
	static unsigned char ucCounter = 0, i, ucImageTemp1, ucImageTemp2;
	static SchedulerDelayCounter_t DelayCounter = 0, DelayCounter1 = 0;

	/* Draw each line of image at 3ms */
	if (Scheduler_HasDelayElapsed(3, &DelayCounter))
	{	
		if (i > 39)
		{
			i = 0;
			
			/* Do some delay between each image draw */
			while (!(Scheduler_HasDelayElapsed(2, &DelayCounter1))) ;			
		}

		ucImageTemp1 = image[i++];
		ucImageTemp2 = image[i++];

		/* Draw image on left side */
		SPI_MasterTransmit (0);
		SPI_MasterTransmit (0);
		SPI_MasterTransmit (ucImageTemp1);
		SPI_MasterTransmit (ucImageTemp2);
		DataLatches_Clock (LEFT_SIDE_DATA_LATCHES);

		/* Draw image on right side */
		SPI_MasterTransmit (0);
		SPI_MasterTransmit (0);
		SPI_MasterTransmit (0);
		SPI_MasterTransmit (0);		
		DataLatches_Clock (RIGHT_SIDE_DATA_LATCHES);
	}
}
	
void Hardware_Init(void)
{
	DataLatches_Init();
	SPI_MasterInit (DATA_ORDER_MSB);

	/* Configure Timer1 for generating interrupt every 1ms */
	TCCR1B |= ((1<<WGM12) | (1<<CS11)); /* CTC mode; clkI/O/8 (From prescaler) */
	OCR1A = 1000;   /* Fcpu = 8MHz; Ftimer = Fcpu / 8 = 1MHz; 1 / 1MHz = 1us; */
					/* 1us * 1000 = 1ms = OCR1A */
	TIMSK1 |= (1<<OCIE1A); /* OCIEnA: Timer/Countern, Output Compare A Match */
							/* Interrupt Enable */
	sei(); /* Enable interrupts */
}
