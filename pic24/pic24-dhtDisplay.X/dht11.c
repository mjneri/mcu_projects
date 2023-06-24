//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// dht11.c -- DHT-11 Sensor Driver
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: dht11 Driver
//      Main reference: https://simple-circuit.com/mplab-xc8-dht11-sensor-pic-mcu/
//
//      Main reference for DHT11 protocol:
//          https://www.electronicwings.com/sensors-modules/dht11
//
// Revisions:
// Revision 0.01 - File Created (2022-10-15)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include "dht11.h"

// Local Functions
static void DHT11_Start(void)
{
    // Start a DHT read by pulling DHTSIG low for 25ms, high for 30탎, then
    // setting DHTSIG as an input.
    DHTSIG_SetDigitalOutput();
    
    // Set low for 25ms to send the start pulse
    DHTSIG_SetLow();
    __delay_ms(25);
    
    // Set DHTSIG high then set it as an input.
    // We wait for the sensor to pull the line low after this.
    DHTSIG_SetHigh();
    DHTSIG_SetDigitalInput();
}

static int DHT11_WaitResponse(void)
{
    // This function is called after DHT11_Start()
    // Wait for a response from the DHT11 here.
    uint16_t microsCnt = 0;
    
    // Wait for DHT11 to pull DHTSIG low. Stop waiting if
    // 1000탎 passes
    while(DHTSIG_GetValue() && (microsCnt < 1000))
    {
        __delay_us(1);
        microsCnt++;
    }
    
    // Timeout error if 1ms passed
    if(microsCnt >= 1000)
    {
        return -1;
    }
    
    // DHTSIG was pulled low. It should be low for ~80탎, but
    // we check for 1000탎 just in case a timeout error occurs
    microsCnt = 0;
    while(!DHTSIG_GetValue() && (microsCnt < 1000))
    {
        __delay_us(1);
        microsCnt++;
    }
    
    // Timeout error
    if(microsCnt >= 1000)
    {
        return -1;
    }
    
    // DHTSIG is now high. It should remain so for ~80탎
    microsCnt = 0;
    while(DHTSIG_GetValue() && (microsCnt < 1000))
    {
        __delay_us(1);
        microsCnt++;
    }
    
    // Timeout error
    if(microsCnt >= 1000)
    {
        return -1;
    }
    
    // At this point, the DHT11 should now start sending the data.
    return 0;
}

// Function definitions
int DHT11_Read(dht11_struct_t *data)
{
    int ret = 0;
    uint8_t bitIndex = 0;
    uint64_t bitStore = 0;
    uint8_t checksum = 0;
    
    if(data == NULL)
    {
        return -1;
    }
    
    DHT11_Start();
    ret = DHT11_WaitResponse();
    
    if(ret < 0)
    {
        return ret;
    }
    
    // Read 40 bits from the sensor
    // A '1' from DHT11 is represented by a 54탎 low pulse, followed by a 70탎 high pulse
    // A '0' from DHT11 is represented by a 54탎 low pulse, followed by a 24탎 high pulse
    
    for (bitIndex = 0; bitIndex < 40; bitIndex++)
    {
        // Wait for the high pulse.
        while(!DHTSIG_GetValue());
        
        // Measure the high pulse's width. Exit the loop once DHTSIG goes low again
        // If the pulse stays high for more than 30탎, then it's definitely a '1'
        __delay_us(30);
        
        // Shift bitStore left; insert a '1' if the DHT sent a logic high
        // We shift left because the DHT11 sends each byte MSB first.
        bitStore = (bitStore << 1);
        
        if(DHTSIG_GetValue())
        {
            bitStore |= 1;
        }
        
        // Wait until DHTSIG goes low.
        while(DHTSIG_GetValue());
    }
    
    // Wait for the 54탎 end of frame to finish
    while(!DHTSIG_GetValue());
    
    //printf("bitIndex %u, bitStore: %llx\r\n", bitIndex, bitStore);
    
    // Store the results to some temporary variables first
    uint8_t tempHumidLo = (bitStore & 0xFF00000000) >> 32;
    uint8_t tempHumidHi = (bitStore & 0x00FF000000) >> 24;
    uint8_t tempTempLo = (bitStore & 0x0000FF0000) >> 16;
    uint8_t tempTempHi = (bitStore & 0x000000FF00) >> 8;
    
    // Bytes 0&1 contain the relative humidity, bytes 2&3 contain the temperature,
    // byte 4 contains the checksum.
    data->humidity = (tempHumidLo) | ((uint16_t)tempHumidHi << 8);
    data->temp = (tempTempLo) | ((uint16_t)tempTempHi << 8);
    checksum = (uint8_t)(bitStore & 0xFF);
    
    uint8_t calcChecksum = ((data->humidity >> 8) & 0xFF) + ((data->humidity) & 0xFF) +
                ((data->temp >> 8) & 0xFF) + ((data->temp) & 0xFF);
    
    //printf("checksum %u, calcChecksum: %u\r\n", checksum, calcChecksum);
    
    if(checksum == calcChecksum)
    {
        // Checksum is good
        return 0;
    }
    else
    {
        return -1;
    }
}

// Reference: https://github.com/adafruit/DHT-sensor-library/blob/master/DHT.cpp
//  readTemperature()
float DHT11_GetTemperature(uint16_t data)
{
    // Byte 2 is Decimal, byte 3 is the fractional part
    // Ex: if byte 2 is 10, and byte 3 is 5, then humidity is "10.5%"
    float f = 0;
    
    uint8_t decimal = (data & 0xFF);
    uint8_t fractional = (data >> 8) & 0xFF;
    
    f = decimal;
    if(fractional & 0x80)
    {
        f = -1 - f;
    }
    
    f += (fractional &0x0F) * 0.1;
    
    return f;
}

// Reference: https://github.com/adafruit/DHT-sensor-library/blob/master/DHT.cpp
//  readHumidity()
float DHT11_GetHumidity(uint16_t data)
{
    // Byte 0 is Decimal, byte 1 is the fractional part
    // Ex: if byte 0 is 10, and byte 1 is 5, then humidity is "10.5%"
    float f = 0;
    
    uint8_t decimal = (data & 0xFF);
    uint8_t fractional = (data >> 8) & 0xFF;
    
    f = decimal + fractional * 0.1;
    
    return f;
}