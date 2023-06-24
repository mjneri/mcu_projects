//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// pixels.c -- WS2813 Driver
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: pixels.c
// Description:
//
// Revisions:
// Revision 0.01 - File Created (2021-08-16)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Include Header files
#include "pixels.h"

// Global Variables
// ...

// Extern variables
// ...

// Local Functions
static void PIXEL_SendData(pixels_data_t pixelData);

// Functions
void PIXEL_Initialize(pixels_data_t *pixelBuffer, uint8_t size)
{
    // Initialize the structure array
    memset(pixelBuffer, 0, size*sizeof(pixels_data_t));
    
    // Clear each LED in the array
    PIXEL_Update(pixelBuffer, size);
    
    // wait until the LEDs reset
    __delay_ms(1);
    
    return;
}

void PIXEL_Clear(pixels_data_t *pixelBuffer, uint8_t size)
{
    // This function is basically the same as PIXEL_Initialize()
    PIXEL_Initialize(pixelBuffer, size);
    return;
}

void PIXEL_SetColor(pixels_data_t *pixel, uint8_t red, uint8_t green, uint8_t blue)
{
    // Set the color values of a specific pixel/LED
    pixel->red = red;
    pixel->green = green;
    pixel->blue = blue;
    
    return;
}

void PIXEL_Update(pixels_data_t *pixelBuffer, const uint8_t size)
{
    // Update each LED
    uint8_t i = 0;
    for(i = 0; i < size; i++)
    {
        PIXEL_SendData(pixelBuffer[i]);
    }
}

static void PIXEL_SendData(pixels_data_t pixelData)
{
    SPI1_ExchangeByte(pixelData.green);
    SPI1_ExchangeByte(pixelData.red);
    SPI1_ExchangeByte(pixelData.blue);
}