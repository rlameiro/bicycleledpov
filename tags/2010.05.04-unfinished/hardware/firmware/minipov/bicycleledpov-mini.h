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

#ifndef _BICYCLELEDPOV_H_
#define _BICYCLELEDPOV_H_

	/* Includes: */
		#include <avr/io.h>
		#include <avr/wdt.h>
		#include <avr/interrupt.h>


		#include <../MyUSB/Version.h>                         // Library Version Information
		#include <../MyUSB/Scheduler/Scheduler.h>             // Simple scheduler for task management
		#include <../Drivers/AT90USB162/SPI.h>					/* SPI drivers */
		#include <../Drivers/DataLatches/595.h>				/* Data latches drivers */
		#include <../Drivers/button/button.h>					/* Button drivers */
		#include <util/delay.h>		

	/* Macros: */
		/* Version 0.1.0 */
		#define BICYCLELEDPOV_VERSION_MAJOR		0
		#define BICYCLELEDPOV_VERSION_MINOR		1
		#define BICYCLELEDPOV_VERSION_REVISION  0
		
		/* Memory of 32kB */
		#define MEMORY_SIZE_BYTE_1				32
		#define MEMORY_SIZE_BYTE_2				0
		#define MEMORY_SIZE_BYTE_3				0	  
						
		#define GET_LINE_CODING				0x21
		#define SET_LINE_CODING				0x20
		#define SET_CONTROL_LINE_STATE		0x22

		#define PROCESS_COMMAND				0
		#define PROCESS_DATA				1		
		

		/* Macros for commands */
		
		/* General commands */
		#define API_COMMAND_DUMMY							1
		#define FIRMWARE_API_COMMAND_RETRIEVE_FIRMWARE_VERSION		2
		
		/* SPI commands */
		#define FIRMWARE_API_COMMAND_SS0_ENABLE						3
		#define FIRMWARE_API_COMMAND_SS0_DISABLE					4
		#define FIRMWARE_API_COMMAND_SS1_ENABLE						5
		#define FIRMWARE_API_COMMAND_SS1_DISABLE					6
		#define FIRMWARE_API_COMMAND_SS2_ENABLE						7
		#define FIRMWARE_API_COMMAND_SS2_DISABLE					8
		#define FIRMWARE_API_COMMAND_SPI_MASTER_TRANSMIT			9
		
		/* Sensor hall effect commands */
		#define FIRMWARE_API_COMMAND_SENSOR_HALL_EFFECT_VCC_ENABLE	10
		#define FIRMWARE_API_COMMAND_SENSOR_HALL_EFFECT_VCC_DISABLE	11
		#define FIRMWARE_API_COMMAND_SENSOR_HALL_EFFECT_READ_DATA	12		
		
		/* DataFlash memory commands */
		#define FIRMWARE_API_COMMAND_DATAFLASH_VCC_ENABLE			13
		#define FIRMWARE_API_COMMAND_DATAFLASH_VCC_DISABLE			14
		#define FIRMWARE_API_COMMAND_DATAFLASH_HOLD_ENABLE			15
		#define FIRMWARE_API_COMMAND_DATAFLASH_HOLD_DISABLE			16
		
		
	/* Function Prototypes: */
		void Hardware_Init(void);

	/* Tasks: */
		TASK(BicycleLEDPOV_Mini);
#endif
