/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F46Q10
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "pixels.h"

// App-level constants
#define RED 0
#define GRN 1
#define BLU 2

// Global Variables
pixels_data_t pixelArray[PIXELCOUNT];
uint8_t lightStates = RED;
uint8_t pixelToUpdate = 0;

// Hardware Setup used:
//      + Explorer 8 Development Board
//      + PIC18F46Q10 PDIP40
// 
// Pin outs:
//      + RC0: CLC1OUT
//
// Connections
//      + Connect Grove WS2813 stick SIG to RC0
//      + VCC to 5V
//      + GND to GND

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    // Open the SPI Port
    SPI1_Open(SPI1_DEFAULT);

    // Initialize the Pixel structure
    PIXEL_Initialize(pixelArray, PIXELCOUNT);
    
    // Turn pixels white for 1sec
    uint8_t i = 0;
    for(i = 0; i < PIXELCOUNT; i++)
    {
        PIXEL_SetColor(&pixelArray[i], 0xFF, 0xFF, 0xFF);
    }
    PIXEL_Update(pixelArray, PIXELCOUNT);
    __delay_ms(2000);
    
    // Clear the pixels
    PIXEL_Clear(pixelArray, PIXELCOUNT);

    while (1)
    {
        switch(lightStates)
        {
            case RED:
                PIXEL_SetColor(&pixelArray[pixelToUpdate], 25, 0, 0);
                lightStates = GRN;
                break;
                
            case GRN:
                PIXEL_SetColor(&pixelArray[pixelToUpdate], 0, 25, 0);
                lightStates = BLU;
                break;
                
            case BLU:
                PIXEL_SetColor(&pixelArray[pixelToUpdate], 0, 0, 25);
                lightStates = RED;
                break;
                
            default:
                break;
        }
        
        // Update the LEDs
        PIXEL_Update(pixelArray, PIXELCOUNT);
        
        // Increment pixelToUpdate
        pixelToUpdate = ++pixelToUpdate % PIXELCOUNT;
        __delay_ms(50);
    }
}
/**
 End of File
*/