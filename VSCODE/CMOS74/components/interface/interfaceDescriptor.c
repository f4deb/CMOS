#include <stdio.h>
#include <string.h>
#include "interfaceDescriptor.h"
#include "interface.h"

#include "sdkconfig.h"

#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_log.h"

#include "../charUtils/include/charUtils.h"
#include "../uartUtils/include/uartUtils.h"
#include "../uartCommand/include/uartCommand.h"


#define TAG "Interface Descriptor"

char status[100];


void printDeviceLine(){

    /*sprintf(status,"|" );
    char *str1="-";
    for (int i = 0;i < 50 ; i++){
        strncat (status,str1,strlen(str1)+1);
    }
    str1="|";
    strncat (status,str1,strlen(str1)+1);
    ESP_LOGE(TAG,"%s",status);
    uartDataBack(status);
*/
}