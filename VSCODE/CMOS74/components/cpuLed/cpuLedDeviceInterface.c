
#include <stdio.h>
#include "cpucLedDeviceInterface.h"

#include "sdkconfig.h"

#include "esp_event.h"
#include "esp_log.h"

const char* getCpucLedDeviceeName(void) {
    return "CpuLed";
}