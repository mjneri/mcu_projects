/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RC4 aliases
#define SW3_TRIS                 TRISCbits.TRISC4
#define SW3_LAT                  LATCbits.LATC4
#define SW3_PORT                 PORTCbits.RC4
#define SW3_WPU                  WPUCbits.WPUC4
#define SW3_OD                   ODCONCbits.ODCC4
#define SW3_ANS                  ANSELCbits.ANSELC4
#define SW3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SW3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SW3_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SW3_GetValue()           PORTCbits.RC4
#define SW3_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SW3_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SW3_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SW3_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SW3_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SW3_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SW3_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SW3_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)
   
// get/set RC5 aliases
#define TX_SUCCESS_TRIS                 TRISCbits.TRISC5
#define TX_SUCCESS_LAT                  LATCbits.LATC5
#define TX_SUCCESS_PORT                 PORTCbits.RC5
#define TX_SUCCESS_WPU                  WPUCbits.WPUC5
#define TX_SUCCESS_OD                   ODCONCbits.ODCC5
#define TX_SUCCESS_ANS                  ANSELCbits.ANSELC5
#define TX_SUCCESS_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define TX_SUCCESS_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define TX_SUCCESS_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define TX_SUCCESS_GetValue()           PORTCbits.RC5
#define TX_SUCCESS_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define TX_SUCCESS_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define TX_SUCCESS_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define TX_SUCCESS_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define TX_SUCCESS_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define TX_SUCCESS_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define TX_SUCCESS_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define TX_SUCCESS_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)
   
// get/set RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_WPU                  WPUDbits.WPUD0
#define IO_RD0_OD                   ODCONDbits.ODCD0
#define IO_RD0_ANS                  ANSELDbits.ANSELD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define IO_RD0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define IO_RD0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define IO_RD0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define IO_RD0_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)
   
// get/set RD1 aliases
#define IO_RD1_TRIS                 TRISDbits.TRISD1
#define IO_RD1_LAT                  LATDbits.LATD1
#define IO_RD1_PORT                 PORTDbits.RD1
#define IO_RD1_WPU                  WPUDbits.WPUD1
#define IO_RD1_OD                   ODCONDbits.ODCD1
#define IO_RD1_ANS                  ANSELDbits.ANSELD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define IO_RD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define IO_RD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define IO_RD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define IO_RD1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)
   
// get/set RD2 aliases
#define HEARTBEAT_LED_TRIS                 TRISDbits.TRISD2
#define HEARTBEAT_LED_LAT                  LATDbits.LATD2
#define HEARTBEAT_LED_PORT                 PORTDbits.RD2
#define HEARTBEAT_LED_WPU                  WPUDbits.WPUD2
#define HEARTBEAT_LED_OD                   ODCONDbits.ODCD2
#define HEARTBEAT_LED_ANS                  ANSELDbits.ANSELD2
#define HEARTBEAT_LED_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define HEARTBEAT_LED_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define HEARTBEAT_LED_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define HEARTBEAT_LED_GetValue()           PORTDbits.RD2
#define HEARTBEAT_LED_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define HEARTBEAT_LED_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define HEARTBEAT_LED_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define HEARTBEAT_LED_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define HEARTBEAT_LED_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define HEARTBEAT_LED_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define HEARTBEAT_LED_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define HEARTBEAT_LED_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)
   
// get/set RD3 aliases
#define RX_SUCCESS_TRIS                 TRISDbits.TRISD3
#define RX_SUCCESS_LAT                  LATDbits.LATD3
#define RX_SUCCESS_PORT                 PORTDbits.RD3
#define RX_SUCCESS_WPU                  WPUDbits.WPUD3
#define RX_SUCCESS_OD                   ODCONDbits.ODCD3
#define RX_SUCCESS_ANS                  ANSELDbits.ANSELD3
#define RX_SUCCESS_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define RX_SUCCESS_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define RX_SUCCESS_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RX_SUCCESS_GetValue()           PORTDbits.RD3
#define RX_SUCCESS_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define RX_SUCCESS_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define RX_SUCCESS_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define RX_SUCCESS_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define RX_SUCCESS_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define RX_SUCCESS_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define RX_SUCCESS_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define RX_SUCCESS_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)
   
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/