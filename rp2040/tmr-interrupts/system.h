//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// system.h -- Header file for system.c
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: system.h
// Description:
//
// Revisions:
// Revision 0.01 - File Created (May 29, 2021)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Header Guards
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

// Project File includes (like stdio.h, etc.)
#include "pico/stdlib.h"            // Includes hardware/gpio.h, pico/stdio.h, pico.h
#include "hardware/timer.h"         // For low-level Timer peripheral APIs
#include "hardware/irq.h"           // For hardware interrupt handling

// Other header files
#include "interrupts.h"

// Define Macros
// ...

// Define System level constants
#define LED_PIN 25                  // Pi Pico LED is mapped to GP25
#define ALM_NUM 0                   // Alarm number used; 4 alarm sources in total
#define ALM_IRQ TIMER_IRQ_0         // Interrupt source for the alarm (refer to Section 2.3.2 of the device datasheet)

// Function prototypes
void SYSTEM_Initialize(void);
void PIN_Initialize(void);
void TMR_Initialize(void);
void INTERRUPT_Initialize(void);

#endif /*_SYSTEM_H_*/