/**
 * @file    ctmu.h
 * @author  MJ Neri
 * @brief   This contains data types &  function prototypes for ctmu.c
 *        
 * 
 * @version 0.1
 * @date    Mar. 17, 2021
 */


#ifndef CTMU_H
#define	CTMU_H

#include "mcc_generated_files/system.h"


// Constants
#define SAMPLEBUFSIZE   4           // amount of samples to store in an array, used for windowed averaging
#define DEBOUNCECOUNT   3           // for debouncing signals
#define TRIPPOINT       0x00B0      // can be determined via trial & error
#define PADCOUNT        2           // no. of touch pads available
#define KEYTRIPDIV      32          // divider for recalculating trip point
#define SAMP_ACC        32          // # of samples to accumulate
#define NUM_AVG         4           // Adds every 'NUM_AVG'th sample to the slow average

// Data type definitions
typedef ADC1_CHANNEL adc_channel_t;         // Values depend on defined ADCx_CHANNEL enum of MCC-generated code.

// NOTE: Commented-out sections are for optional features; an attempt to make this library
// portable to other PIC24F devices.

//typedef uint16_t io_port_t;                 // Used along with IO_PORT_GROUP
//
//typedef enum
//{
//    IO_PORTA = 0,
//    IO_PORTB
//} IO_PORT_GROUP;

typedef struct
{
    adc_channel_t     adcChannel;           // ADC Channel of the touchpad
//    IO_PORT_GROUP     ioPortGroup;          // Determines port group of ADC channel
//    io_port_t         ioPortPin;            // Determines which pin in the port group belongs to the ADC channel
    
    uint8_t     pressedCount;               // Used for debouncing
    uint8_t     unpressedCount;             // Used for debouncing
    bool        isPressed;                  // Determines if the touchpad is pressed
    bool        isHeld;                     // Determines if the touchpad is held
    
    uint16_t    samplesBuf[SAMPLEBUFSIZE];  // Buffer that contains previous 'BUFSIZE' samples
    uint8_t     bufIndex;                   // used to index samplesBuf
    uint8_t     samples;                    // Contains the amount of samples within samplesBuf
    uint16_t    slowAvgDelay;               // used for slow averaging
    
    uint16_t    tripValue;
    uint16_t    hystValue;
    
    uint32_t    average;                    // contains the average of the samplesBuf values
    uint32_t    smallAverage;
    
    int         touchCount;                 // determines how many times a touchpad is pressed
    
} touch_Object;

typedef enum
{
    TOUCHPAD_1 = 0,
    TOUCHPAD_2
} TOUCHPAD_INDEX;


// Function prototypes

/**
 * @summary 
 * 
 * @description 
 * @param
 * @return
 */
void init_CTMU(void);
void init_Touch(void);
uint16_t readCTMU(adc_channel_t channel);
void checkTouchStatus(TOUCHPAD_INDEX padIndex);
void recalcTrip(void);

#endif	/* CTMU_H */

