//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// system.h -- System Header file
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: system.h
// Description:
//
// Revisions:
// Revision 0.01 - File Created (May 27, 2021)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Header guards
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

// Include files for the project
// NOTE: When adding Pico libraries, CMakeLists.txt will need to be modified
#include <stdio.h>
#include "pico/stdlib.h"            // Path: pico-sdk/src/common/pico_stdlib
                                    // This library includes multiple libraries including pico.h, hardware/gpio.h, etc.

// System Macros/Defines
#define LED_PIN 25

// Function headers
void PIN_Initialize(void);

#endif /*_SYSTEM_H_*/