//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// main.c -- Main C Firmware code
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: main.c
// Description: This contains the C Firmware to blink the Pico's LED.
//
// Revisions:
// Revision 0.01 - File Created (May 27, 2021)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Include Files
#include "system.h"

// Global Variables
// ...

int main(void)
{
    // Initialization
    PIN_Initialize();

    while(1)
    {
        sleep_ms(500);			// This function is defined in pico/time.h

        // Toggle the LED pin
        gpio_xor_mask(1 << LED_PIN);
    }
}