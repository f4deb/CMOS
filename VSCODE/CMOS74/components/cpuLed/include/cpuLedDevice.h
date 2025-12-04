#ifndef CPU_LED_DEVICE_H
#define CPU_LED_DEVICE_H

#include "../../charUtils/include/charUtils.h"

#include "../../device/include/deviceInterface.h"

void cpuLedDeviceInterface(void);

void cpuLedDevice(char rxBuffer[50]);

#endif