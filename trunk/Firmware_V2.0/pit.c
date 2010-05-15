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

extern long i;

/* Each PIT interrupt happens at ~1ms */
void PIT_irq_handler (void)
{
    i++;

    AT91C_BASE_PITC->PITC_PIVR;
}

void delay (long ms)
{
    long initial_ms = i;
    while (i < (initial_ms + ms)) ; /* wait for ms */
}

void PIT_setup (void)
{
    /* PIV = 1ms * (MCLK/16) ~= 3003 */
    AT91C_BASE_PITC->PITC_PIMR = 3003;

    AT91C_BASE_AIC->AIC_IDCR = (1 << AT91C_ID_SYS);
    AT91C_BASE_AIC->AIC_SMR[AT91C_ID_SYS] = AT91C_AIC_PRIOR_LOWEST;
    AT91C_BASE_AIC->AIC_SVR[AT91C_ID_SYS] = (unsigned int) PIT_irq_handler;
    AT91C_BASE_AIC->AIC_ICCR = (1 << AT91C_ID_SYS);
    AT91C_BASE_AIC->AIC_IECR = (1 << AT91C_ID_SYS);

    /* enable PIT and interrupt */
    AT91C_BASE_PITC->PITC_PIMR |= (AT91C_PITC_PITEN | AT91C_PITC_PITIEN);
}
