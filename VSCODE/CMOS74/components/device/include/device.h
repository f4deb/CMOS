#ifndef DEVICE_H
#define DEVICE_H

#include "transmitMode.h"

// forward declaration
struct Device;
typedef struct Device Device;

/**
* Defines the structure used to describe a device.
*/
struct Device {
    /** The Header of the device */
    const char* header;
    /** Which bus the device use. */
    TransmitMode transmitMode;
    /** The address as char (useful for zigbee for example). */
    char* addressString;
    /** The address (only for remote transmitMode). In case of addressString, address contains a checksum of addressString. */
    int address;
    /** The Name of the Device */
    char* name; 
    /** The help listing */
    DeviceList* deviceList;
} ;

#endif
