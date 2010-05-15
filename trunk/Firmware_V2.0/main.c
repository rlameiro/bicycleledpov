/*
 * BicycLED POV
 *
 * Copyright (C) Jorge Pinto aka Casainho, 2010.
 *
 *   casainho [at] gmail [dot] com
 *
 *
 * Released under the GPL Licence, Version 3
 */

#include "at91sam7s256.h"
#include "board.h"
#include "main.h"

long i = 0;

extern unsigned enableIRQ(void);

int main (void)
{
    /* Initialize the Atmel AT91SAM7S256 (watchdog, PLL clock, default
    interrupts, etc.) */
    LowLevelInit ();

    /* Initialize Timer 0, to get delay (ms) working */
    PIT_setup ();
    enableIRQ ();

    /* Initialize PIO and SSC for driving LED drivers */
    SSC_Init ();

    /* Endless loop */
    while (1)
    {
        SSC_Send (0x0F0F0F0F);
        delay (2000);
        SSC_Send (0x55555555);
        delay (2000);
    }
}
