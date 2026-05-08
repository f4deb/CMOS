#include <stdio.h>
#include <string.h>
#include "interfaceDescriptor.h"
#include "interface.h"

#include "sdkconfig.h"

#include "esp_log.h"

#include "../charUtils/include/charUtils.h"
#include "../uartUtils/include/uartUtils.h"


#define TAG "Interface Descriptor"


    char status11[50] = "TOTO";

void printDeviceLine(){



    sprintf(status11,"|" );
    char *str1="-";
    for (int i = 0;i < 50 ; i++){
        strncat (status11,str1,strlen(str1)+1);
    }
    str1="|";
    strncat (status11,str1,strlen(str1)+1);
    ESP_LOGE(TAG,"%s",status11);
    uartDataBack(status11);

}