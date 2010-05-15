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

static long i = 0;

/* Each Timer0 interrupt happens at ~1ms */
void timer0_irq_handler (void)
{
    i++;
}

void delay (long ms)
{
    long initial_ms = i;
    while (i < (initial_ms + ms)) ; /* wait for ms */
}

void timer0_setup (void)
{
    /* Enable the Timer0 peripheral clock */
    /* enable Timer0 peripheral clock */
    AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_TC0);

    AT91C_BASE_TC0->TC_CCR = AT91C_TC_CLKDIS; /* disable TC clock */
    AT91C_BASE_TC0->TC_IDR = 0xFFFFFFFF; /* disable interrupts */
    AT91C_BASE_TC0->TC_SR; /* clear status register */
    AT91C_BASE_TC0->TC_CMR = 0x4004; /* Set mode: TCCLKS = 1 (TIMER_CLOCK5) */

    /*  Timer Calculation:   What count gives 1 msec time-out?
     *
     *    TIMER_CLOCK5 = MCK / 1024  = 48054841 / 1024  =  46928 hz
     *
     *     TIMER_CLOCK5 Period = 1 / 46928  =  21.309239686 microseconds
     *
     *     A little algebra:  1 msec = count * 21.3092396896*10**-6
     *                        count =  1 / 21.3092396896*10**-3
     *                        count ~=  47
     */
    AT91C_BASE_TC0->TC_RC = 47;

    /* Set up the AIC  registers for Timer 0 */
    /* disable timer 0 interrupt in AIC Interrupt Disable Command Register */
    AT91C_BASE_AIC->AIC_IDCR = (1 << AT91C_ID_TC0);
    /* set the interrupt source type and priority */
    AT91C_BASE_AIC->AIC_SMR[AT91C_ID_TC0] =  0;
    /* set the TC0 IRQ handler address in AIC Source */
    AT91C_BASE_AIC->AIC_SVR[AT91C_ID_TC0] = (unsigned int) timer0_irq_handler;
    AT91C_BASE_AIC->AIC_ICCR = (1 << AT91C_ID_TC0); /* clear interrupt */
    AT91C_BASE_TC0->TC_IER = AT91C_TC_CPCS; /* enable RC compare interrupt */

    /* Enable the TC0 interrupt in AIC Interrupt Enable Command Register */
    AT91C_BASE_AIC->AIC_IECR = (1<<AT91C_ID_TC0);

    AT91C_BASE_TC0->TC_CCR = AT91C_TC_SWTRG; /* enable the clock/start it */






#if 0
    AT91C_BASE_TCB->TCB_BCR = 0; /* SYNC trigger not used */

    AT91C_BASE_TCB->TCB_BMR = 0x15; /* external clocks not used */

    AT91C_BASE_TC0->TC_CCR = 0x5; /* enable the clock and start it */

    AT91C_BASE_TC0->TC_CMR = 0x4004; /* TCCLKS = 1 (TIMER_CLOCK5) */
    /* CPCTRG = 1 (RC Compare resets the counter and restarts the clock) */
    /* WAVE   = 0 (Capture mode enabled) */

/*  Timer Calculation:   What count gives 1 msec time-out?
 *
 *    TIMER_CLOCK5 = MCK / 1024  = 48054841 / 1024  =  46928 hz
 *
 *     TIMER_CLOCK5 Period = 1 / 46928  =  21.309239686 microseconds
 *
 *     A little algebra:  1 msec /*  Timer Calculation:   What count gives 1 msec time-out?
 *
 *    TIMER_CLOCK5 = MCK / 1024  = 48054841 / 1024  =  46928 hz
 *
 *     TIMER_CLOCK5 Period = 1 / 46928  =  21.309239686 microseconds
 *
 *     A little algebra:  1 msec = count * 21.3092396896*10**-6
 *                        count =  1 / 21.3092396896*10**-3
 *                        count ~=  47
 */
    AT91C_BASE_TC0->TC_RC = 47;


    AT91C_BASE_TC0->TC_IDR = 0xEF; /* disable all except RC compare interrupt */
#endif
}

