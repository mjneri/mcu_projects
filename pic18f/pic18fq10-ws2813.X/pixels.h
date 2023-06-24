//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// pixels.h -- Header file for pixels.c
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: pixels.h
// Description: This header file provides data type definitions for
//              the WS2813 driver.
//
// Revisions:
// Revision 0.01 - File Created (2021-08-16)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Header Guards
#ifndef _PIXELS_H_
#define _PIXELS_H_

// Header files
#include "mcc_generated_files/mcc.h"

// Define Macros
// ...

// Define Application-level constants
#define PIXELCOUNT 10

// pixels_data_t
//      + This structure holds RGB channel data for an
//          individual WS2813 LED
//      + It's expected that an array of this data type is declared.
//          No linked lists for now.
typedef struct
{
    uint8_t green;
    uint8_t red;
    uint8_t blue;
    
} pixels_data_t;

// PIXEL_Initialize(void)
//      + Initializes the pixel structure array
void PIXEL_Initialize(pixels_data_t *pixelBuffer, uint8_t size);

// PIXEL_Clear(void)
//      + Turns off all LEDs in the array
void PIXEL_Clear(pixels_data_t *pixelBuffer, uint8_t size);

// PIXEL_SetColor();
//      + Sets the RGB brightness values of an individual LED
void PIXEL_SetColor(pixels_data_t *pixel, uint8_t red, uint8_t green, uint8_t blue);

// PIXEL_Update()
//      + Updates the actual LEDs based on the structure array
void PIXEL_Update(pixels_data_t *pixelBuffer, const uint8_t size);

#endif /*_PIXELS_H_*/