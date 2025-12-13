#ifndef CPU_LED_DEVICE_H
#define CPU_LED_DEVICE_H

#include "../../charUtils/include/charUtils.h"

#include "../../device/include/device.h"
#include "../../device/include/deviceInterface.h"

#define CPU_LED_DEVICE_DEBUG 1


void cpuLedDeviceHandle(char rxBuffer[50]);

#endif