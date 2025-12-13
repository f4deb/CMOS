
#include <stdio.h>
#include <string.h>

#include "cpuLedDeviceInterface.h"
#include "cpuLedDevice.h"

#include "sdkconfig.h"

#include "esp_event.h"
#include "esp_log.h"

#include "../../device/include/device.h"


void  initCpuLedDevice(void){
    // for compil
}


char* cpuLedDeviceGetName(void) {
    return "CpuLed";
}

char* cpuLedDeviceGetHeader(void){
    return CPU_LED_INTERFACE_HEADER;
}