//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// lcd16x2.h -- 16x2 LCD Driver
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: lcd16x2.h
// Description: Ported from my CoE115 projects
//  https://github.com/mjneri/coe115-dump/blob/master/ME1/me1_functions.h
//
// Revisions:
// Revision 0.01 - File Created (2022-10-15)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef _LCD16X2_H_
#define	_LCD16X2_H_

#include <xc.h>
#include <stdint.h>
#include <string.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"

// Macros for use with the LCD
#define CLEARDISPLAY    0x0001
#define RETURNHOME      0x0002

#define ENTRYMODE_INCR  0x0006
#define ENTRYMODE_DECR  0x0004
#define ENTRYMODE_SHL   0x0005
#define ENTRYMODE_SHR   0x0004

#define DISPLAY         0x0008
#define DISPLAY_ON      0x000C
#define DISPLAY_CURSOR  0x000A
#define DISPLAY_BLINKON 0x0009

#define SETDDRAMADDR    0x0080

/**
 * Pin definitions (w/ LCD in 4-bit nibble mode)
 *      LCD_D7 - RB15
 *      LCD_D6 - RB14
 *      LCD_D5 - RB13
 *      LCD_D4 - RB9
 *      LCD_RS - RB8
 *      LCD_E  - RB7
 * 
 * All pins are in PORTB for ease of coding.
 * 
 * LCD Datasheet: http://users.ece.utexas.edu/~valvano/Datasheets/LCDOptrex.pdf
 */

// Macros for LCD pins
#define D7_out  _LATB15
#define D6_out  _LATB14
#define D5_out  _LATB13
#define D4_out  _LATB9
#define RS_out  _LATB8
#define E_out   _LATB7

#define D7_bm 0x8000
#define D6_bm 0x4000
#define D5_bm 0x2000
#define D4_bm 0x0200
#define RS_bm 0x0100
#define E_bm  0x0080

#define D7_pos  0xF
#define D6_pos  0xE
#define D5_pos  0xD
#define D4_pos  0x9
#define RS_pos  0x8
#define E_pos   0x7

// Function prototypes

void LCD_Initialize(void);
void LCD_Send(uint16_t data);
void LCD_Print(char *str);
uint16_t LCD_CharConvert(char c);


#endif	/*_LCD16X2_H_*/