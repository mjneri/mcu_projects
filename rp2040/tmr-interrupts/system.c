//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// system.c -- System Initialization & Configuration code
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: system.c
// Description:
//
// Revisions:
// Revision 0.01 - File Created (May 29, 2021)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Include Header files
#include "system.h"

// Global Variables
// ...

// Extern variables
extern const uint32_t periodicDelay_ms;

// Functions
void SYSTEM_Initialize(void)
{
    PIN_Initialize();
    TMR_Initialize();
    INTERRUPT_Initialize();
}

void PIN_Initialize(void)
{
    // Configure the LED pin as an output
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void TMR_Initialize(void)
{
    // Enable alarm interrupts for alarm 0. Note: INTE = Interrupt Enable
    hw_set_bits(&timer_hw->inte, 1 << ALM_NUM);

    // Register the callback function/ISR for Alarm interrupts
    irq_set_exclusive_handler(ALM_IRQ, _TimerInterruptHandler);

    // Enable Alarm Interrupts
    // Note: To enable peripheral interrupts, interrupts should be enabled within the peripheral registers
    // as well as the core registers(?)
    irq_set_enabled(ALM_IRQ, true);

    // Arm the Alarm register
    uint64_t delay = timer_hw->timerawl + (periodicDelay_ms * 1000);
    timer_hw->alarm[ALM_NUM] = (uint32_t)delay;
}

void INTERRUPT_Initialize(void)
{
    // Set interrupt priority; Default priority is 0x80 (PICO_DEFAULT_IRQ_PRIORITY)
    irq_set_priority(ALM_IRQ, 0x90);
}
