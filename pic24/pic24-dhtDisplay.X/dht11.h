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
// Revisions:
// Revision 0.01 - File Created (2022-10-15)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef DHT11_H
#define	DHT11_H


#include <xc.h>
#include <stdint.h>
#include <string.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"

typedef struct
{
    uint16_t humidity;
    uint16_t temp;
} dht11_struct_t;

/* Function:
 *  int DHT11_Read(dht11_struct_t *data)
 * 
 * @summary     Reads sensor data from the DHT11
 * 
 * @param       data - pointer to dht11_struct_t where the data will be stored.
 * 
 * @return      0 - if DHT read was successful
 *              1 - if DHT read was unsuccessful or if the sensor is not yet ready
 */
int DHT11_Read(dht11_struct_t *data);

float DHT11_GetTemperature(uint16_t data);
float DHT11_GetHumidity(uint16_t data);

#endif	/* DHT11_H */

