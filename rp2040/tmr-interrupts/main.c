//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// main.c -- Main C Firmware code
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: main.c
// Description: This sketch is based on the 'timer_lowlevel' example in pico-examples
//              The timer peripheral is configured for periodic interrupts.
//              Since the device's timer is significantly different from the timer peripherals
//              in a PIC MCU (where timers can automatically reset on period match), the
//              Alarm registers will need to be re-armed every time to get periodic interrupts.
//
// Revisions:
// Revision 0.01 - File Created (May 29, 2021)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Include header files here
#include "system.h"

// Global Variables
// Define variables that will be accessed by ISRs as 'volatile'
volatile bool toggleLED = false;        // Flag that determines whether the LED should be toggled
const uint32_t periodicDelay_ms = 100;  // Delay in ms; determines the rate of periodic alarm interrupts
                                        // Note: since 

// Extern Variables
// ...

int main(void)
{
    // Initialize all modules
    SYSTEM_Initialize();

    while (1)
    {
        // Write application code here
        if (toggleLED)
        {
            toggleLED = false;           // Reset flag
            gpio_xor_mask(1 << LED_PIN); // Toggle the LED
        }
    }
}