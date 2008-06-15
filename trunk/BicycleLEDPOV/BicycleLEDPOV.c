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

#include "BicycleLEDPOV.h"

/* Scheduler Task List */
TASK_LIST
{
	{ Task: USB_USBTask      					, TaskStatus: TASK_STOP },
	{ Task: CDC_Task							, TaskStatus: TASK_STOP },
	{ Task: PCLink_Task 					    , TaskStatus: TASK_STOP },
	{ Task: MakePOV_Task						, TaskStatus: TASK_STOP },	
	{ Task: TestSensorHallEffect_Task			, TaskStatus: TASK_STOP },	
};

/* Globals: */
CDC_Line_Coding_t LineCoding = { BaudRateBPS: 9600,
                                 CharFormat:  OneStopBit,
                                 ParityType:  Parity_None,
                                 DataBits:    8            };

RingBuff_t        Rx_Buffer;
RingBuff_t        Tx_Buffer;

unsigned char rxbuff, txbuff, rxbuffele, txbuffele;

ISR(TIMER0_COMPA_vect, ISR_BLOCK)
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
	
	/* Ringbuffer Initialization */
	Buffer_Initialize(&Rx_Buffer);
	Buffer_Initialize(&Tx_Buffer);

	/* Initialize Scheduler so that it can be used */
	Scheduler_Init();

	/* Initialize USB Subsystem */
	USB_Init();

	/* Scheduling - routine never returns, so put this last in the main function */
	Scheduler_Start();
}

EVENT_HANDLER(USB_Connect)
{
	/* Start USB management task */
	Scheduler_SetTaskMode(USB_USBTask, TASK_RUN);
	Scheduler_SetTaskMode(MakePOV_Task, TASK_STOP);
}

EVENT_HANDLER(USB_Disconnect)
{
	Scheduler_SetTaskMode(USB_USBTask, TASK_STOP);
	Scheduler_SetTaskMode(CDC_Task, TASK_STOP);
	Scheduler_SetTaskMode(PCLink_Task, TASK_STOP);
	Scheduler_SetTaskMode(TestSensorHallEffect_Task, TASK_STOP);
	Scheduler_SetTaskMode(MakePOV_Task, TASK_RUN);
}

EVENT_HANDLER(USB_ConfigurationChanged)
{
	/* Setup CDC Notification, Rx and Tx Endpoints */
	Endpoint_ConfigureEndpoint(CDC_NOTIFICATION_EPNUM, EP_TYPE_INTERRUPT,
		                       ENDPOINT_DIR_IN, CDC_NOTIFICATION_EPSIZE,
	                           ENDPOINT_BANK_SINGLE);

	Endpoint_ConfigureEndpoint(CDC_TX_EPNUM, EP_TYPE_BULK,
		                       ENDPOINT_DIR_IN, CDC_TXRX_EPSIZE,
	                           ENDPOINT_BANK_DOUBLE);

	Endpoint_ConfigureEndpoint(CDC_RX_EPNUM, EP_TYPE_BULK,
		                       ENDPOINT_DIR_OUT, CDC_TXRX_EPSIZE,
	                           ENDPOINT_BANK_DOUBLE);

	/* Start CDC task */
	Scheduler_SetTaskMode(CDC_Task, TASK_RUN);	
	Scheduler_SetTaskMode(PCLink_Task, TASK_RUN);
	PORTD &= ~(1<<PD4); /* Turn off LED */
}

EVENT_HANDLER(USB_UnhandledControlPacket)
{
	uint8_t* LineCodingData = (uint8_t*)&LineCoding;

	Endpoint_Ignore_Word();

	/* Process CDC specific control requests */
	switch (Request)
	{
		case GET_LINE_CODING:
			if (RequestType == (REQDIR_DEVICETOHOST | REQTYPE_CLASS | REQREC_INTERFACE))
			{
				Endpoint_ClearSetupReceived();

				for (uint8_t i = 0; i < sizeof(LineCoding); i++)
				  Endpoint_Write_Byte(*(LineCodingData++));	
				
				Endpoint_ClearSetupIN();
				while (!(Endpoint_IsSetupINReady()));
				
				while (!(Endpoint_IsSetupOUTReceived()));
				Endpoint_ClearSetupOUT();
			}
			
			break;
		case SET_LINE_CODING:
			if (RequestType == (REQDIR_HOSTTODEVICE | REQTYPE_CLASS | REQREC_INTERFACE))
			{
				Endpoint_ClearSetupReceived();

				while (!(Endpoint_IsSetupOUTReceived()));

				for (uint8_t i = 0; i < sizeof(LineCoding); i++)
				  *(LineCodingData++) = Endpoint_Read_Byte();

				Endpoint_ClearSetupOUT();

				Endpoint_ClearSetupIN();
				while (!(Endpoint_IsSetupINReady()));
			}
	
			break;
		case SET_CONTROL_LINE_STATE:
			if (RequestType == (REQDIR_HOSTTODEVICE | REQTYPE_CLASS | REQREC_INTERFACE))
			{
				Endpoint_ClearSetupReceived();
				
				Endpoint_ClearSetupIN();
				while (!(Endpoint_IsSetupINReady()));
			}
	
			break;
	}
}

TASK(CDC_Task)
{
	if (USB_IsConnected)
	{
		/* Select the Serial Rx Endpoint */
		Endpoint_SelectEndpoint(CDC_RX_EPNUM);
		
		if (Endpoint_ReadWriteAllowed())
		{
			/* Read the recieved data endpoint into the transmission buffer */
			while (Endpoint_BytesInEndpoint())
			{
				/* Wait until the buffer has space for a new character */
				while (!((BUFF_STATICSIZE - Rx_Buffer.Elements)));
			
				/* Store each character from the endpoint */
				Buffer_StoreElement(&Rx_Buffer, Endpoint_Read_Byte());
			}
			
			/* Clear the endpoint buffer */
			Endpoint_ClearCurrentBank();
		}

		/* Select the Serial Tx Endpoint */
		Endpoint_SelectEndpoint(CDC_TX_EPNUM);

		/* Check if the Tx buffer contains anything to be sent to the host */
		if (Tx_Buffer.Elements)
		{
			/* Wait until Serial Tx Endpoint Ready for Read/Write */
			while (!(Endpoint_ReadWriteAllowed()));
			
			/* Check before sending the data if the endpoint is completely full */
			bool IsFull = (Endpoint_BytesInEndpoint() == CDC_TXRX_EPSIZE);
			
			/* Write the transmission buffer contents to the recieved data endpoint */
			while (Tx_Buffer.Elements && (Endpoint_BytesInEndpoint() < CDC_TXRX_EPSIZE))
			  Endpoint_Write_Byte(Buffer_GetElement(&Tx_Buffer));
			
			/* Send the data */
			Endpoint_ClearCurrentBank();

			/* If a full endpoint was sent, we need to send an empty packet afterwards to terminate the transfer */
			if (IsFull)
			{
				/* Wait until Serial Tx Endpoint Ready for Read/Write */
				while (!(Endpoint_ReadWriteAllowed()));

				/* Send an empty packet to terminate the transfer */
				Endpoint_ClearCurrentBank();
			}
		}
	}
}

TASK(PCLink_Task)
{
	static unsigned char
		ucCommand = 0,
		ucNumberDataBytes = 0;
	
	if (Rx_Buffer.Elements)
	{
		if (ucNumberDataBytes == 0)
			ucCommand = Buffer_GetElement (&Rx_Buffer);

		switch (ucCommand)
		{			
			case DUMMY:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
			ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				ucNumberDataBytes--;
			}				
			break;
				
			case RETRIEVE_FIRMWARE_VERSION:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
					ucNumberDataBytes = 4;
					
			while (Tx_Buffer.Elements < BUFF_STATICSIZE && ucNumberDataBytes > 0)
			{
				switch (ucNumberDataBytes)
				{
					case 4:
					Buffer_StoreElement (&Tx_Buffer, ucCommand);
					break;
													
					case 3:
					Buffer_StoreElement (&Tx_Buffer, BICYCLELEDPOV_VERSION_MAJOR);
					break;
						
					case 2:
					Buffer_StoreElement (&Tx_Buffer, BICYCLELEDPOV_VERSION_MINOR);
					break;

					case 1:
					Buffer_StoreElement (&Tx_Buffer, BICYCLELEDPOV_VERSION_REVISION);
					break;
							
					default:
					break;
				}		
							
			ucNumberDataBytes--;
			}
			break;
							
			case TEST_LEDS:
			/* First byte of this command, fill the NumberDataBytes */
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 5;

			while (Tx_Buffer.Elements < BUFF_STATICSIZE && ucNumberDataBytes > 0)
			{	
				switch (ucNumberDataBytes)
				{
					case 5: /* Send back the number of the command */
					Buffer_StoreElement (&Tx_Buffer, ucCommand);
					break;					

					case 4:/* Send the 4 bytes to LEDs drivers */
						/* TODO */
					break;
					
					case 3:
						/* TODO */					
					break;
					
					case 2:
						/* TODO */					
					break;
					
					case 1:
						/* TODO */					
					break;
						
					default:					
					break;
				}

			ucNumberDataBytes--;	
			}
			break;				
					
			case TEST_SENSOR_HALL_EFFECT:					
			/* First byte of this command, fill the NumberDataBytes */
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 2;		
			
			switch (ucNumberDataBytes)
			{
				case 2: /* Send back the number of the command */
				if (Tx_Buffer.Elements < BUFF_STATICSIZE)
				{
					Buffer_StoreElement (&Tx_Buffer, ucCommand);
					ucNumberDataBytes--;
				}
				break;					

			 	case 1: /* See If we should turn on or off the test */						
				if (Buffer_GetElement (&Rx_Buffer) == 1)
				{
					Scheduler_SetTaskMode(TestSensorHallEffect_Task, TASK_RUN);
					
					/* Turn on the source voltage for sensor hall effect */
					PORTD |= (1<<PD1);
				}
				
				else
				{
					Scheduler_SetTaskMode(TestSensorHallEffect_Task, TASK_STOP);
					
					/* Turn off LED and source voltage for sensor hall effect */
					PORTD &= ~((1<<PD4) | (1<<PD1));
				}	
				
				ucNumberDataBytes--;
				break;
					
				default:
				break;
			}
			
			default:			
			break;
		}		
	}
}
	
void Hardware_Init(void)
{
	/* Output pin for the LED and sensor heffect ect */
	DDRD |= ((1<<PD4) | (1<<PD1));
	
	/* Millisecond timer initialization, with output compare interrupt enabled */
	OCR0A  = 0x7D;
	TCCR0A = (1 << WGM01);
	TCCR0B = ((1 << CS01) | (1 << CS00));
	TIMSK0 = (1 << OCIE0A);
}

TASK(MakePOV_Task)
{
	PORTD |= (1<<PD4); /* Turn on LED */
}

TASK(TestSensorHallEffect_Task)
{
	if (bit_is_clear(PIND,PD0))
	{
		PORTD |= (1<<PD4); /* Turn on LED */
	}
	
	else
	{
		PORTD &= ~(1<<PD4); /* Turn off LED */
	}
}
