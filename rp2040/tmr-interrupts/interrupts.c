//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// interrupts.c -- Interrupt service routines
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: interrupts.c
// Description:
//
// Revisions:
// Revision 0.01 - File Created (May 29, 2021)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Header files
#include "interrupts.h"

// Global variables
// ...

// Extern Variables
extern volatile bool toggleLED;
extern const uint32_t periodicDelay_ms;

// ISRs
void _TimerInterruptHandler(void)
{
    // Clear interrupt flag/irq by writing to timer_hw->intr
    // Note: hw_clear_bits() is an API for clearing bits within peripheral registers
    hw_clear_bits(&timer_hw->intr, 1 << ALM_NUM);

    // Set toggleLED flag
    toggleLED = true;

    // Re-arm the alarm register
    uint64_t delay = timer_hw->timerawl + (periodicDelay_ms * 1000);
    timer_hw->alarm[ALM_NUM] = (uint32_t) delay;
}