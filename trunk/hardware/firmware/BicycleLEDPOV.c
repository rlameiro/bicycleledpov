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
};

/* Globals: */
CDC_Line_Coding_t LineCoding = { BaudRateBPS: 9600,
                                 CharFormat:  OneStopBit,
                                 ParityType:  Parity_None,
                                 DataBits:    8            };

RingBuff_t        Rx_Buffer;
RingBuff_t        Tx_Buffer;


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
			}	EEPROM_Init();
		}
	}
}

TASK(PCLink_Task)
{
	static unsigned char
	ucCommand = 0,
	ucLastCommand = 0,
	ucNumberDataBytes = 0,
	ucFlagNextByte = false;

	static unsigned long int
	uliAddress;

	if (Rx_Buffer.Elements)
	{
		if (ucNumberDataBytes == 0)
		{
			ucLastCommand = ucCommand; /* Save the last command */
			ucCommand = Buffer_GetElement (&Rx_Buffer); /* Store the new command */
		}

		/* Process the commands */
		switch (ucCommand)
		{							
			/****************************************************************/
			/* API_COMMAND_GET_HARDWARE_PROPERTIES							*/
			/*																*/
			case API_COMMAND_GET_HARDWARE_PROPERTIES:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes < 1)
				ucNumberDataBytes = 13;
					
			while (Tx_Buffer.Elements < BUFF_STATICSIZE && ucNumberDataBytes > 0)
			{
				switch (ucNumberDataBytes)
				{
					case 13:
					/* Report this command as implemented */
					Buffer_StoreElement (&Tx_Buffer, REPORT_COMMAND_IMPLEMENTED);
					break;
													
					case 12:
					Buffer_StoreElement (&Tx_Buffer, API_VERSION);
					break;
						
					case 11:
					Buffer_StoreElement (&Tx_Buffer, API_EXTENDED_VERSION);
					break;

					case 10:
					Buffer_StoreElement (&Tx_Buffer, FIRMWARE_VERSION);
					break;

					case 9:
					Buffer_StoreElement (&Tx_Buffer, NUMBER_OF_RADIAL_LINES_BYTE_01);
					break;

					case 8:
					Buffer_StoreElement (&Tx_Buffer, NUMBER_OF_RADIAL_LINES_BYTE_02);
					break;
							
					case 7:
					Buffer_StoreElement (&Tx_Buffer, NUMBER_OF_LED_PER_RADIAL_LINE_BYTE_01);
					break;

					case 6:
					Buffer_StoreElement (&Tx_Buffer, NUMBER_OF_LED_PER_RADIAL_LINE_BYTE_02);
					break;

					case 5:
					Buffer_StoreElement (&Tx_Buffer, IMAGE_COLOUR_PROPERTIES_BYTE_01);
					break;

					case 4:
					Buffer_StoreElement (&Tx_Buffer, IMAGE_COLOUR_PROPERTIES_BYTE_02);
					break;

					case 3:
					Buffer_StoreElement (&Tx_Buffer, IMAGE_COLOUR_PROPERTIES_BYTE_03);
					break;

					case 2:
					Buffer_StoreElement (&Tx_Buffer, IMAGE_COLOUR_PROPERTIES_BYTE_04);
					break;

					case 1:
					Buffer_StoreElement (&Tx_Buffer, NUMBER_OF_INDEPENDENT_LED_STRIPS);
					break;

					default:
					break;
				}		
							
			ucNumberDataBytes--;
			}
			break;
					
			/****************************************************************/
			/* API_COMMAND_GET_MEMORY_SIZE									*/
			/*																*/			
			case API_COMMAND_GET_MEMORY_SIZE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes < 1)
				ucNumberDataBytes = 4;

			while (Tx_Buffer.Elements < BUFF_STATICSIZE && ucNumberDataBytes > 0)
			{
				switch (ucNumberDataBytes)
				{
					case 4:
					/* Report this command as implemented */
					Buffer_StoreElement (&Tx_Buffer, REPORT_COMMAND_IMPLEMENTED);
					break;
													
					case 3:
					Buffer_StoreElement (&Tx_Buffer, MEMORY_SIZE_BYTE_1);
					break;
						
					case 2:
					Buffer_StoreElement (&Tx_Buffer, MEMORY_SIZE_BYTE_2);
					break;

					case 1:
					Buffer_StoreElement (&Tx_Buffer, MEMORY_SIZE_BYTE_3);
					break;
							
					default:
					break;
				}		
							
			ucNumberDataBytes--;
			}
			break;

			/****************************************************************/
			/* API_COMMAND_CLEAR_ALL_MEMORY									*/
			/* EEPROM memory don't need to be cleared before writing on it,	*/
			/* so we do nothing.											*/
			/*																*/
			case API_COMMAND_CLEAR_ALL_MEMORY:

			/* Report this command as implemented */
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				Buffer_StoreElement (&Tx_Buffer, REPORT_COMMAND_IMPLEMENTED);
			}
			break;

			/****************************************************************/
			/* API_COMMAND_READ_MEMORY_BYTE									*/
			/*																*/			
			case API_COMMAND_READ_MEMORY_BYTE:
			
			/* Find if it's a sequencial read byte */
			/* It's a sequencial read byte */
			if (ucLastCommand == API_COMMAND_READ_MEMORY_BYTE)
				ucFlagNextByte = true;
			
			/* It's a read only byte */
			else
				ucFlagNextByte = false;
				
            /* First byte of this command, fill the NumberDataBytes */
            if (ucNumberDataBytes < 1)
			{
				ucNumberDataBytes = 4;
			}

			/* Process the first byte of the command */	
			if (ucNumberDataBytes == 4 && Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Report this command as implemented */
				Buffer_StoreElement (&Tx_Buffer, REPORT_COMMAND_IMPLEMENTED);
				ucNumberDataBytes--;
			}
				
			/* Read the next sequencial byte */
			if (ucFlagNextByte)
			{
				if (Tx_Buffer.Elements < BUFF_STATICSIZE)
				{
					uliAddress++;
					Buffer_StoreElement (&Tx_Buffer, (EEPROM_ReadByte (uliAddress)));
					
					ucNumberDataBytes = 0;
				}
			}

			/* Read the byte of the given address */
			else
			{
				while (Rx_Buffer.Elements > 0)
				{
					switch (ucNumberDataBytes)
					{
						case 3:
						uliAddress = (Buffer_GetElement (&Rx_Buffer)) * 256 * 256;
						break;
						
						case 2:
						uliAddress += (Buffer_GetElement (&Rx_Buffer)) * 256;
						break;

						case 1:
						if (Tx_Buffer.Elements < BUFF_STATICSIZE)
						{
							uliAddress += Buffer_GetElement (&Rx_Buffer);
							Buffer_StoreElement (&Tx_Buffer, (EEPROM_ReadByte (uliAddress)));				
						}						
						break;
							
						default:
						break;
					}	

				ucNumberDataBytes--;	
				}
			}
			break;

			/****************************************************************/
			/* API_COMMAND_WRITE_MEMORY_BYTE								*/
			/*																*/			
			case API_COMMAND_WRITE_MEMORY_BYTE:
			
			/* Find if it's a sequencial write byte */
			/* It's a sequencial write byte */
			if (ucLastCommand == API_COMMAND_WRITE_MEMORY_BYTE)
				ucFlagNextByte = true;
			
			/* It's a write only byte */
			else
				ucFlagNextByte = false;				
				
            /* First byte of this command, fill the NumberDataBytes */
            if (ucNumberDataBytes < 1)
			{
				ucNumberDataBytes = 5;
			}
			
			/* Process the first byte of the command */	
			if (ucNumberDataBytes == 5 && Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Report this command as implemented */
				Buffer_StoreElement (&Tx_Buffer, REPORT_COMMAND_IMPLEMENTED);
				ucNumberDataBytes--;
			}
				
			/* Write the next sequencial byte */
			if (ucFlagNextByte)
			{
				if (Rx_Buffer.Elements > 0)
				{
					uliAddress++;
					EEPROM_WriteByte (uliAddress, Buffer_GetElement (&Rx_Buffer));
					
					ucNumberDataBytes = 0;
				}
			}

			/* Write the byte of the given address */
			else
			{
				while (Rx_Buffer.Elements > 0)
				{
					switch (ucNumberDataBytes)
					{
						case 4:
						uliAddress = Buffer_GetElement (&Rx_Buffer) * 256 * 256;
						break;
						
						case 3:
						uliAddress += Buffer_GetElement (&Rx_Buffer) * 256;
						break;

						case 2:
						uliAddress += Buffer_GetElement (&Rx_Buffer);
						break;

						case 1:
						EEPROM_WriteByte (uliAddress, Buffer_GetElement (&Rx_Buffer));
						break;
							
						default:
						break;
					}	

				ucNumberDataBytes--;	
				}
			}
			break;

#if 0
			/* Estended API	*/
			/* Next commands are from extended API */ 

			case API_COMMAND_SS0_ENABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Enable SS0 line */
				SS0_ENABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				ucNumberDataBytes--;
			}		
			break;			

			case API_COMMAND_SS0_DISABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Disable SS0 line */
				SS0_DISABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				ucNumberDataBytes--;
			}		
			break;			

			case COMMAND_SS1_ENABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Enable SS1 line */
				SS1_ENABLE;
			
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				ucNumberDataBytes--;
			}		
			break;			

			case API_COMMAND_SS1_DISABLE:
			/* First byte of this command, fill the NumberDataBytes */
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Disable SS1 line */
				SS1_DISABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				ucNumberDataBytes--;
			}		
			break;

			case API_COMMAND_SS2_ENABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Enable SS2 line */
				SS2_ENABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				ucNumberDataBytes--;
			}		
			break;			

			case API_COMMAND_SS2_DISABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Disable SS2 line */
				SS2_DISABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				ucNumberDataBytes--;
			}		
			break;				

				
			case FIRMWARE_API_COMMAND_SENSOR_HALL_EFFECT_VCC_ENABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Enable Vcc on sensor hall effect */
				SENSOR_HALL_EFFECT_VCC_ENABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				
				ucNumberDataBytes--;
			}		
			break;

			case API_COMMAND_SENSOR_HALL_EFFECT_VCC_DISABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Disable Vcc on sensor hall effect */
				SENSOR_HALL_EFFECT_VCC_DISABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				
				ucNumberDataBytes--;
			}		
			break;
				
			case API_COMMAND_SENSOR_HALL_EFFECT_READ_DATA:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if ( (Tx_Buffer.Elements + 1) < BUFF_STATICSIZE)
			{
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				
				/* Send one byte with values 1 or 0 accordinly of sensor hall effect data */
				Buffer_StoreElement (&Tx_Buffer, SENSOR_HALL_EFFECT_IS_SET);
				
				ucNumberDataBytes--;
			}
			break;

			case API_COMMAND_DATAFLASH_VCC_ENABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Enable Vcc on DataFlash memory */
				DATAFLASH_VCC_ENABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				
				ucNumberDataBytes--;
			}		
			break;

			case API_COMMAND_DATAFLASH_VCC_DISABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Disable Vcc on DataFlash memory */
				DATAFLASH_VCC_DISABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				
				ucNumberDataBytes--;
			}		
			break;				

			case API_COMMAND_DATAFLASH_HOLD_ENABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Enable hold on DataFlash memory */
				DATAFLASH_HOLD_ENABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				
				ucNumberDataBytes--;
			}		
			break;

			case API_COMMAND_DATAFLASH_HOLD_DISABLE:
			/* First byte of this command, fill the NumberDataBytes */			
			if (ucNumberDataBytes <= 0)
				ucNumberDataBytes = 1;
				
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				/* Disable hold on DataFlash memory */
				DATAFLASH_HOLD_DISABLE;
				
				/* Send back the value of the command */
				Buffer_StoreElement (&Tx_Buffer, ucCommand);
				
				ucNumberDataBytes--;
			}		
			break;				

#endif		
			default:
			/* Report this command as unimplemented */
			if (Tx_Buffer.Elements < BUFF_STATICSIZE)
			{
				Buffer_StoreElement (&Tx_Buffer, REPORT_COMMAND_UNIMPLEMENTED);
			}			
			
			break;
		}
	}
}
	
void Hardware_Init(void)
{
	BUTTON_INIT;
	SensorHallEffect_Init();
	DataLatches_Init();
	SPI_MasterInit (DATA_ORDER_MSB);
	EEPROM_Init(); /* EEPROM must be initialized after SPI! */
}

TASK(MakePOV_Task)
{
	SPI_MasterTransmit (0x00);
	SPI_MasterTransmit (0x80);
	SPI_MasterTransmit (0x01);
	SPI_MasterTransmit (0x00);
	DataLatches_Clock (LEFT_SIDE_DATA_LATCHES);

	SPI_MasterTransmit (0x00);
	SPI_MasterTransmit (0x00);
	SPI_MasterTransmit (0x00);
	SPI_MasterTransmit (0x00);
	DataLatches_Clock (RIGHT_SIDE_DATA_LATCHES);
}
