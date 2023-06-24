/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ64GB002
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/clock.h"
#include "lcd16x2.h"
#include "mcc_generated_files/pin_manager.h"
#include "dht11.h"
#include "mcc_generated_files/tmr1.h"

volatile bool readDHT = false;

void TimerCallback(void)
{
    readDHT = true;
    USERLED_Toggle();
}

/*
                         Main application
 */
int main(void)
{
    dht11_struct_t sensorData;
    float temp, humidity;
    char lcdBuffer[40];
    
    memset(lcdBuffer, 0, sizeof(lcdBuffer));
    
    // initialize the device
    SYSTEM_Initialize();
    __delay_ms(1000);
    LCD_Initialize();
    TMR1_SetInterruptHandler(TimerCallback);
    
    LCD_Send(DISPLAY_ON);   // Turns on display without turning on the cursor
    LCD_Print("PIC24 Base\nBoard v2");
    __delay_ms(1000);
    LCD_Send(CLEARDISPLAY);
    
    while (1)
    {
        // Add your application code
        if(readDHT)
        {
            readDHT = false;
            DHT11_Read(&sensorData);
            temp = DHT11_GetTemperature(sensorData.temp);
            humidity = DHT11_GetHumidity(sensorData.humidity);
            
            snprintf(lcdBuffer, 40, "Temp: %.1f *C\nHumidity: %.1f%%", temp, humidity);
            printf("%s", lcdBuffer);
            LCD_Send(RETURNHOME);
            LCD_Print(lcdBuffer);
        }
    }
    return 1;
}
/**
 End of File
*/

