//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// lcd16x2.c -- 16x2 LCD Driver
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: lcd16x2.c
// Description: Ported from my CoE115 projects
//  https://github.com/mjneri/coe115-dump/blob/master/ME1/me1_functions.h
//
// Revisions:
// Revision 0.01 - File Created (2022-10-15)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include "lcd16x2.h"

/**
 * Pin definitions (w/ LCD in 4-bit nibble mode)
 *      LCD_D7 - RB15
 *      LCD_D6 - RB14
 *      LCD_D5 - RB13
 *      LCD_D4 - RB9
 *      LCD_RS - RB8
 *      LCD_E  - RB7
 */

void LCD_Initialize(void)
{
    // Main reference: Section 2.2.2 - Software Initialization
    // http://users.ece.utexas.edu/~valvano/Datasheets/LCDOptrex.pdf
    
    // RB[5] = E
    // RB[4] = RS
    // RB[3:0] = D[7:4]
    // E, RS, D<7:4>
    
    LATB = LATB & ~(D7_bm|D6_bm|D5_bm|D4_bm|RS_bm|E_bm);
    __delay_ms(15);
    LATB = LATB | (D5_bm|D4_bm|E_bm);
    __delay_us(100);
    LATB = LATB & ~(E_bm);
    
    LATB = LATB & ~(D7_bm|D6_bm|D5_bm|D4_bm|RS_bm|E_bm);
    __delay_ms(4);
    __delay_us(100);
    LATB = LATB | (D5_bm|D4_bm|E_bm);
    __delay_us(100);
    LATB = LATB & ~(E_bm);
    
    LATB = LATB & ~(D7_bm|D6_bm|D5_bm|D4_bm|RS_bm|E_bm);
    __delay_ms(4);
    __delay_us(100);
    LATB = LATB | (D5_bm|D4_bm|E_bm);
    __delay_us(100);
    LATB = LATB & ~(E_bm);
    
    LATB = LATB & ~(D7_bm|D6_bm|D5_bm|D4_bm|RS_bm|E_bm);
    __delay_ms(4);
    __delay_us(100);
    LATB = LATB | (D5_bm|E_bm);
    __delay_us(100);
    LATB = LATB & ~(E_bm);
    
    LCD_Send(0x0028);           // Function set
    LCD_Send(DISPLAY);          // Display off
    LCD_Send(CLEARDISPLAY);     // Clear display
    LCD_Send(ENTRYMODE_INCR);   // Entry mode set
    LCD_Send(0x000F);           // Display on
    return;
}

void LCD_Send(uint16_t data)
{
    // data<7:0> contains the data bits D<7:0>
    // data<8> contains RS
    // Upper nibble is sent first.
    uint16_t highNib = (data >> 4) & 0x000F;     // Upper nibble
    uint16_t lowNib = (data & 0x000F);           // Lower nibble
    uint16_t dataRS = (data >> 8) & 0x0001;      // "RS" field from data
    
    LATB = LATB & ~(D7_bm|D6_bm|D5_bm|D4_bm|RS_bm|E_bm);
    __delay_ms(4);
    __delay_us(100);
    LATB = LATB | (((highNib << 12) & (D7_bm|D6_bm|D5_bm)) | ((highNib << 9) & D4_bm));
    LATB = LATB | (dataRS << RS_pos);
    LATB = LATB | E_bm;
    __delay_us(100);
    LATB = LATB & ~(E_bm);
    
    LATB = LATB & ~(D7_bm|D6_bm|D5_bm|D4_bm|RS_bm|E_bm);
    __delay_us(100);
    LATB = LATB | (((lowNib << 12) & (D7_bm|D6_bm|D5_bm)) | ((lowNib << 9) & D4_bm));
    LATB = LATB | (dataRS << RS_pos);
    LATB = LATB | E_bm;
    __delay_us(100);
    LATB = LATB & ~(E_bm);
    return;
}

void LCD_Print(char *str)
{
    unsigned int len = strlen(str);
    unsigned int i = 0;
    for(i = 0; i < len; i++){
        LCD_Send(LCD_CharConvert(str[i]));
    }
    return;
}

uint16_t LCD_CharConvert(char c)
{
    switch(c)
    {
        case ' ': return 0x0120;
        case '!': return 0x0121;
        case '"': return 0x0122;
        case '#': return 0x0123;
        case '$': return 0x0124;
        case '%': return 0x0125;
        case '&': return 0x0126;
        case '\'': return 0x0127;
        case '(': return 0x0128;
        case ')': return 0x0129;
        case '*': return 0x012a;
        case '+': return 0x012b;
        case ',': return 0x012c;
        case '-': return 0x012d;
        case '.': return 0x012e;
        case '/': return 0x012f;
        case '0': return 0x0130;
        case '1': return 0x0131;
        case '2': return 0x0132;
        case '3': return 0x0133;
        case '4': return 0x0134;
        case '5': return 0x0135;
        case '6': return 0x0136;
        case '7': return 0x0137;
        case '8': return 0x0138;
        case '9': return 0x0139;
        case ':': return 0x013a;
        case ';': return 0x013b;
        case '<': return 0x013c;
        case '=': return 0x013d;
        case '>': return 0x013e;
        case '?': return 0x013f;
        case '@': return 0x0140;
        case 'A': return 0x0141;
        case 'B': return 0x0142;
        case 'C': return 0x0143;
        case 'D': return 0x0144;
        case 'E': return 0x0145;
        case 'F': return 0x0146;
        case 'G': return 0x0147;
        case 'H': return 0x0148;
        case 'I': return 0x0149;
        case 'J': return 0x014a;
        case 'K': return 0x014b;
        case 'L': return 0x014c;
        case 'M': return 0x014d;
        case 'N': return 0x014e;
        case 'O': return 0x014f;
        case 'P': return 0x0150;
        case 'Q': return 0x0151;
        case 'R': return 0x0152;
        case 'S': return 0x0153;
        case 'T': return 0x0154;
        case 'U': return 0x0155;
        case 'V': return 0x0156;
        case 'W': return 0x0157;
        case 'X': return 0x0158;
        case 'Y': return 0x0159;
        case 'Z': return 0x015a;
        case '[': return 0x015b;
        case '¥': return 0x015c;
        case ']': return 0x015d;
        case '^': return 0x015e;
        case '_': return 0x015f;
        case '`': return 0x0160;
        case 'a': return 0x0161;
        case 'b': return 0x0162;
        case 'c': return 0x0163;
        case 'd': return 0x0164;
        case 'e': return 0x0165;
        case 'f': return 0x0166;
        case 'g': return 0x0167;
        case 'h': return 0x0168;
        case 'i': return 0x0169;
        case 'j': return 0x016a;
        case 'k': return 0x016b;
        case 'l': return 0x016c;
        case 'm': return 0x016d;
        case 'n': return 0x016e;
        case 'o': return 0x016f;
        case 'p': return 0x0170;
        case 'q': return 0x0171;
        case 'r': return 0x0172;
        case 's': return 0x0173;
        case 't': return 0x0174;
        case 'u': return 0x0175;
        case 'v': return 0x0176;
        case 'w': return 0x0177;
        case 'x': return 0x0178;
        case 'y': return 0x0179;
        case 'z': return 0x017a;
        case '{': return 0x017b;
        case '|': return 0x017c;
        case '}': return 0x017d;
        case '\n': return 0x00c0;   // set ddram addr
    }
    return 0;
}



/**
 End of File
*/

