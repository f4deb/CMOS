#include <stdio.h>
#include "device.h"

#include "sdkconfig.h"

#include "esp_event.h"
#include "esp_log.h"

bool initDevice(const Device* device) {
    bool result = true;
    /* DeviceDescriptor* deviceDescriptor = device->descriptor;
    DeviceInterface* deviceInterface = device->deviceInterface;

    const char* deviceName = deviceInterface->deviceGetName();
    OutputStream* logStream = getInfoOutputStreamLogger();

    unsigned length = appendString(logStream, deviceName);
    appendSpaces(logStream, 18 - length);

    if (deviceDescriptor != NULL) {
        clearLastError();
        deviceDescriptor->deviceInit();

        result = deviceDescriptor->deviceIsOk();

        if (result) {
            appendString(logStream, "OK");
        }
        else {
            appendString(logStream, "KO (");
            appendDec(logStream, getLastError());
            append(logStream, ')');
        }
        deviceDescriptor->initErrorCode = getLastError();
    }
    // TODO : Manage when REMOTE ...
    println(logStream);
    */
    return result;
}