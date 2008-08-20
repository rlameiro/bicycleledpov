/*
             MyUSB Library
     Copyright (C) Dean Camera, 2008.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com

 Released under the LGPL Licence, Version 3
*/

/** \file
 *
 *  Main USB interrupt vector handler. This file manages the main USB interrupt vector, for handling such
 *  events as VBUS interrupts (on supported USB AVR models), device connections and disconnections, etc.
 */

#ifndef __USBINT_H__
#define __USBINT_H__

	/* Includes: */
		#include <avr/io.h>
		#include <stdbool.h>
		
		#include "../../../Common/Common.h"
		#include "../LowLevel/LowLevel.h"
		#include "../LowLevel/USBMode.h"
		#include "Events.h"
		
	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif

	/* Public Interface - May be used in end-application: */
		/* Macros: */
			/** Vector name for the common endpoint and pipe vector. This can be used to write an ISR handler
			 *  for the endpoint and pipe events, to make certain USB functions interrupt rather than poll
			 *  driven.
			 */
			#define ENDPOINT_PIPE_vect                       USB_COM_vect
	
			/** Enables the given USB interrupt vector (such as the ENDPOINT_INT_* and PIPE_INT_* vectors in
			 *  Endpoint.h and Pipe.h).
			 */
			#define USB_INT_Enable(int)              MACROS{ USB_INT_GET_EN_REG(int)   |=   USB_INT_GET_EN_MASK(int);   }MACROE

			/** Disables the given USB interrupt vector.
			 *
			 *  \see USB_INT_Enable()
			 */
			#define USB_INT_Disable(int)             MACROS{ USB_INT_GET_EN_REG(int)   &= ~(USB_INT_GET_EN_MASK(int));  }MACROE

			/** Resets the given USB interrupt flag, so that the interrupt is re-primed for the next firing. */
			#define USB_INT_Clear(int)               MACROS{ USB_INT_GET_INT_REG(int)  &= ~(USB_INT_GET_INT_MASK(int)); }MACROE
			
			/** Returns boolean false if the given USB interrupt is disabled, or true if the interrupt is currently
			 *  enabled.
			 */
			#define USB_INT_IsEnabled(int)                 ((USB_INT_GET_EN_REG(int)   &    USB_INT_GET_EN_MASK(int)) ? true : false)

			/** Returns boolean true if the given interrupt flag is set (i.e. the condition for the interrupt has occurred,
			 *  but the interrupt vector is not neccesarily enabled), otherwise returns false.
			 */
			#define USB_INT_HasOccurred(int)               ((USB_INT_GET_INT_REG(int)  &    USB_INT_GET_INT_MASK(int)) ? true : false)
		
		/* Throwable Events: */
			/** This module raises the USB Connected interrupt when the AVR is attached to a host while in device
			 *  USB mode.
			 */
			RAISES_EVENT(USB_Connect);

			/** This module raises the USB Disconnected interrupt when the AVR is removed from a host while in
			 *  device USB mode.
			 */
			RAISES_EVENT(USB_Disconnect);

			#if defined(USB_FULL_CONTROLLER) || defined(__DOXYGEN__)
				/** This module raises the VBUS Change event when the current VBUS status (present or not present) has
				 *  changed.
				 *
				 *  \note Not all USB AVR models support VBUS interrupts; this event only exists on supported AVRs.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_VBUSChange);

				/** This module raises the VBUS Connect event when the VBUS line is powered.
				 *
				 *  \note Not all USB AVR models support VBUS interrupts; this event only exists on supported AVRs.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_VBUSConnect);

				/** This module raises the VBUS Disconnect event when power is removed from the VBUS line.
				 *
				 *  \note Not all USB AVR models support VBUS interrupts; this event only exists on supported AVRs.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_VBUSDisconnect);
			#endif

			#if defined(USB_CAN_BE_DEVICE) || defined(__DOXYGEN__)
				/** This module raises the Suspended event when the host suspends the USB interface of the AVR
				 *  whilst running in device mode.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_Suspend);

				/** This module raises the Wake Up event when the host resumes the USB interface of the AVR
				 *  whilst running in device mode.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_WakeUp);

				/** This module raises the USB Reset event when the host resets the USB interface of the AVR
				 *  whilst running in device mode.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_Reset);
			#endif
			
			#if defined(USB_CAN_BE_HOST) || defined(__DOXYGEN__)
				/** This module raises the Host Error event when the VBUS line voltage dips below the minimum threshold
				 *  while running in host mode.
				 *
				 *  \note Not all USB AVR models support host mode; this event only exists on supported AVRs.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_HostError);

				/** This module raises the Device Unattached event when an attached device is removed from the AVR whilst
				 *  running in host mode.
				 *
				 *  \note Not all USB AVR models support host mode; this event only exists on supported AVRs.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_DeviceUnattached);
			#endif

			#if defined(USB_CAN_BE_BOTH) || defined(__DOXYGEN__)
				/** This module raises the UID Change event when the UID line changes in value on dual-role devices.
				 *
				 *  \note Not all USB AVR models support host mode and thus the UID pin; this event only exists on
				 *        supported AVRs.
				 *
				 *  \see Events.h for more information on this event.
				 */
				RAISES_EVENT(USB_UIDChange);
			#endif
			
	/* Private Interface - For use in library only: */
	#if !defined(__DOXYGEN__)
		/* Inline Functions: */
			static inline void USB_INT_DisableAllInterrupts(void)
			{
				#if defined(USB_FULL_CONTROLLER)
					#if !defined(__AVR_ATmega32U4__)
						USBCON &= ~((1 << VBUSTE) | (1 << IDTE));					
					#else					
						USBCON &= ~(1 << VBUSTE);					
					#endif
				#endif
				
				#if defined(USB_CAN_BE_HOST)
				UHIEN   = 0;
				OTGIEN  = 0;
				#endif
				
				#if defined(USB_CAN_BE_DEVICE)
				UDIEN   = 0;
				#endif
			}

			static inline void USB_INT_ClearAllInterrupts(void)
			{
				#if defined(USB_FULL_CONTROLLER)
				USBINT  = 0;
				#endif
				
				#if defined(USB_CAN_BE_HOST)
				UHINT   = 0;
				OTGINT  = 0;
				#endif
				
				#if defined(USB_CAN_BE_DEVICE)
				UDINT   = 0;
				#endif
			}

		/* Macros: */
			#define USB_INT_GET_EN_REG(a, b, c, d)           a
			#define USB_INT_GET_EN_MASK(a, b, c, d)          b
			#define USB_INT_GET_INT_REG(a, b, c, d)          c
			#define USB_INT_GET_INT_MASK(a, b, c, d)         d

			#define USB_INT_VBUS                             USBCON, (1 << VBUSTE) , USBINT, (1 << VBUSTI)
			#define USB_INT_IDTI                             USBCON, (1 << IDTE)   , USBINT, (1 << IDTI)
			#define USB_INT_WAKEUP                           UDIEN , (1 << WAKEUPE), UDINT , (1 << WAKEUPI)
			#define USB_INT_SUSPEND                          UDIEN , (1 << SUSPE)  , UDINT , (1 << SUSPI)
			#define USB_INT_EORSTI                           UDIEN , (1 << EORSTE) , UDINT , (1 << EORSTI)
			#define USB_INT_DCONNI                           UHIEN , (1 << DCONNE) , UHINT , (1 << DCONNI)
			#define USB_INT_DDISCI                           UHIEN , (1 << DDISCE) , UHINT , (1 << DDISCI)
			#define USB_INT_BCERRI                           OTGIEN, (1 << BCERRE) , OTGINT, (1 << BCERRI)
			#define USB_INT_VBERRI                           OTGIEN, (1 << VBERRE) , OTGINT, (1 << VBERRI)
			#define USB_INT_SOFI                             UDIEN,  (1 << SOFE)   , UDINT , (1 << SOFI)
			#define USB_INT_HSOFI                            UHIEN,  (1 << HSOFE)  , UHINT , (1 << HSOFI)
			#define USB_INT_RSTI                             UHIEN , (1 << RSTE)   , UHINT , (1 << RSTI)
			#define USB_INT_SRPI                             OTGIEN, (1 << SRPE)   , OTGINT, (1 << SRPI)
	#endif
	
	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif
		
#endif
