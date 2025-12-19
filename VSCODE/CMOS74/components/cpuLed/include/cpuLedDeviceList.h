#ifndef CPU_LED_DEVICE_LIST_H
#define CPU_LED_DEVICE_LIST_H

#include <stdint.h>

#include "../../interface/include/constants.h"
#include "../../interface/include/interface.h"

// forward declaration
struct DeviceList;
typedef struct DeviceList DeviceList;

/**
* Defines the structure used to describe a device.
*/
struct DeviceList {
    /** The Number of the device */
    uint8_t number;
    /** quantity of device. */
    uint8_t max;
    /** The header */
    char header[SIZE_HEADER];
    /** The Name of the Device */
    char* headerName; 
    /** The command of the Device */
    char commandHeader[SIZE_COMMAND_HEADER]; 
    /** The command of the Device */
    char* commandName; 

} ;

#endif