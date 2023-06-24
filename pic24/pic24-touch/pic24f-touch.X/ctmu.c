/**
 * @file    ctmu.c
 * @author  MJ Neri
 * @brief   This module contains user functions for touch detection
 *        
 * 
 * @version 0.1
 * @date    Mar. 17, 2021
 */

// Header Files
#include "ctmu.h"

// Global variables defined in main.c
// ...

// Global variables
touch_Object touchpad[PADCOUNT];

// Macros
#define PAD touchpad[padIndex]

// Functions
void init_CTMU(void)
{
    // Configure CTMU
    CTMUCON = 0x007C;           // Most settings default; make sure CTMU is turned off
                                // EDG1STAT & EDG2STAT = 1, everything else is don't care
    CTMUICON = 0x8700;          // Set current source to 55uA, -62% trim
    
    CTMUCONbits.CTMUEN = 1;     // Enable CTMU
    
    // Enable ADC
    // select AN3 as input
    ADC1_ChannelSelect(channel_RB1_AN3);

    // Turn on the ADC module
    AD1CON1bits.ADON = 1;
    
    CTMUCONbits.IDISSEN     = 1;         // Drain any charge on the circuit
    __delay_us(10);
    CTMUCONbits.IDISSEN     = 0;
    __delay_us(1);
}

void init_Touch(void)
{
    // initialize touch_Object to 0
    memset(touchpad, 0, sizeof(touchpad));
    
    // Set the ADC channel of the touchpads
    touchpad[TOUCHPAD_1].adcChannel = channel_RB1_AN3;
    touchpad[TOUCHPAD_2].adcChannel = channel_RB2_AN4;
    
    // Set the io port group & pin of the touchpads
//    touchpad[TOUCHPAD_1].ioPortGroup = IO_PORTB;
//    touchpad[TOUCHPAD_1].ioPortPin = 1;
//    
//    touchpad[TOUCHPAD_2].ioPortGroup = IO_PORTB;
//    touchpad[TOUCHPAD_2].ioPortPin = 2;
    
    
    int i = 0;
    for(i = 0; i < PADCOUNT; i++)
    {
        touchpad[i].tripValue = 500;
        touchpad[i].hystValue = 250;
    }
}

uint16_t readCTMU(adc_channel_t channel)
{
    // This function oversamples the touchpad to filter out noise
    
    uint32_t accumulator = 0;   // Contains accumulated value for ADC samples
    int i = 0;                  // loop index
    
    for(i = 0; i < SAMP_ACC; i++)
    {
        // Make sure capacitive sensors are at 0V
        // Set touchpads as digital outputs & tie them to ground to drain charges
        AD1PCFG &= ~((1 << channel_RB1_AN3) | (1 << channel_RB2_AN4));
        TRISB &= 0xFFF9;
        LATB = PORTB & 0xFFF9;
        __delay_us(1);

        // Set touchpads back to analog inputs
        AD1PCFG |= ((1 << channel_RB1_AN3) | (1 << channel_RB2_AN4));
        TRISB |= 0x0006;

        ADC1_ChannelSelect(channel);

        // Discharge ADC S&H Cap
        __delay_us(1);
        CTMUCONbits.IDISSEN = 1;
        __delay_us(10);
        CTMUCONbits.IDISSEN = 0;
        __delay_us(1);

        // Enable CTMU current source to start charging the connected capacitive sensor
        CTMUCONbits.EDG1STAT = 0;
        Nop();Nop();Nop();Nop();Nop();

        // Disable current source
        CTMUCONbits.EDG1STAT = 1;
        
        // Start ADC conversion
        accumulator += ADC1_GetConversion(channel);
    }
    
    return (uint16_t)(accumulator/SAMP_ACC);
}

void checkTouchStatus(TOUCHPAD_INDEX padIndex)
{
    // Variables
    uint32_t sampleTotal = 0;
    uint16_t averagedADRES = 0;
    int i = 0;
    
    averagedADRES = readCTMU(PAD.adcChannel);
    
    // Reset bufIndex before it "overflows"
    if(PAD.bufIndex > SAMPLEBUFSIZE-1)
    {
        PAD.bufIndex = 0;
    }
    
    // Add every ADC result to the buffer
    if(PAD.samples < SAMPLEBUFSIZE)
    {
        PAD.samplesBuf[PAD.bufIndex++] = averagedADRES;
        PAD.samples++;
    }
    else
    {
        PAD.samplesBuf[PAD.bufIndex++] = averagedADRES;
    }

    // Get the average of the stored samples
    sampleTotal = 0;
    for(i = 0; i < PAD.samples; i++)
    {
        sampleTotal += PAD.samplesBuf[i];
    }

    PAD.average = sampleTotal/PAD.samples;

    // If average ADC result exceeds trip point, start debouncing
    if(PAD.average < TRIPPOINT)
    {
        PAD.unpressedCount = 0;
        if(PAD.pressedCount >= DEBOUNCECOUNT)
        {
            PAD.isPressed = true;
            PAD.pressedCount = 0;
        }
        else
        {
            PAD.pressedCount++;
        }
    }
    else
    {
        PAD.pressedCount = 0;
        if(PAD.unpressedCount >= DEBOUNCECOUNT)
        {
            PAD.isPressed = false;
            PAD.unpressedCount = 0;
        }
        else
        {
            PAD.unpressedCount++;
        }
    }
}

void recalcTrip(void)
{
    int i;
	for(i = 0; i<PADCOUNT; i++)
	{
		touchpad[i].tripValue = (touchpad[i].average/KEYTRIPDIV);
		//	hystValue[i] = tripValue[i] / 5;
		touchpad[i].hystValue = touchpad[i].tripValue / 2;
	}
}
