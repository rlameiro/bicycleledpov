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

void SSC_Init (void)
{
    /* Configure PIO */
    /* enables peripheral control of the pin */
    AT91C_BASE_PIOA->PIO_PDR = (AT91C_PIO_PA16 | AT91C_PIO_PA17);

    /* assigns the I/O line to the Peripheral A function -- SSC */
    AT91C_BASE_PIOA->PIO_ASR = (AT91C_PIO_PA16 | AT91C_PIO_PA17);

    /* Configure SSC peripheral clock */
    /* enables peripheral clock to SSC */
    AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_SSC);

    /* Configure interrupts */
    /* disable SSC interrupt in AIC Interrupt Disable Command Reg */
    AT91C_BASE_AIC->AIC_IDCR = (1 << AT91C_ID_SSC);

    /* clear the SSC interrupt in AIC Interrupt Clear Command Register */
    AT91C_BASE_AIC->AIC_ICCR = (1 << AT91C_ID_SSC);

    /* disable all SSC interrupts */
    AT91C_BASE_SSC->SSC_IDR = ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3)
           | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)
           | (1 << 10) | (1 << 11));

    /* Configure SSC TK clock */
    /* MCK/(2*[SSC_CMR]) = 48054841 Hz/(2*32) ~= 750.857Hz */
    AT91C_BASE_SSC->SSC_CMR = 32;

    AT91C_BASE_SSC->SSC_TCMR = ((0 << 0) | /* divided Clock */
                (2 << 2) | /* transmit Clock only during data transfers */
                (0 << 5) | /* the data outputs (Data and Frame Sync signals)
                are shifted out on Transmit Clock falling edge. */
                (0 << 6) | /* transmit clock gating: none, continuous clock */
                (0 << 8) | /* transmit start: continuous, as soon as a word is
                written in the SSC_THR Register (if Transmit is enabled), and
                 immediately after the end of transfer of the previous data. */
                (0 << 16) | /* transmit start delay */
                (0 << 24)); /* transmit period divider selection */

    AT91C_BASE_SSC->SSC_TFMR = ((31 << 0) | /* data length = x + 1 */
                 (0 << 5) | /* data default value */
                 (1 << 7) | /* Most Significant Bit First */
                 (0 << 8) | /* Data Number per frame */
                 (0 << 16) | /* Transmit Frame Sync Length */
                 (0 << 20) | /* Selected Transmit Frame Sync Signal: none */
                 (1 << 23) | /* SC_TSHR value is shifted out during the
                 transmission of the Transmit Frame Sync signal. */
                 (0 << 24)); /* Frame Sync Edge Detection */

    /* enable SSC Transmitter */
    AT91C_BASE_SSC->SSC_CR = AT91C_SSC_TXEN;
}

void SSC_Send (long data)
{
    AT91C_BASE_SSC->SSC_THR = data; /* send data */
    while (!AT91C_BASE_SSC->SSC_THR & AT91C_SSC_TXEMPTY) ; /* wait for finish */
}
