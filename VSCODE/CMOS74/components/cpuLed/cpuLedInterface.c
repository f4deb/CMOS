#include <stdio.h>
#include <string.h>
#include "cpuLedInterface.h"

#include "sdkconfig.h"

#include "esp_event.h"
#include "esp_log.h"

#include "../charUtils/include/charUtils.h"

#include "../cpuLed/include/cpuLed.h"
#include "../interface/include/interface.h"
#include "../uartCommand/include/uartCommand.h"
#include "../../../../esp-idf/components/esp_driver_uart/include/driver/uart.h"

#define TAG "CPU Led Interface"

void cpuLedInterface(char rxBuffer[50]){
    char str[CPU_LED_INTERFACE_COMMAND_SIZE];
    char status[20];
    if (CPU_LED_INTERFACE_DEBUG) ESP_LOGE(TAG, "%s ", rxBuffer);

    stringToString(str,rxBuffer, CPU_LED_INTERFACE_COMMAND_SIZE);

    if (CPU_LED_INTERFACE_DEBUG) ESP_LOGE(TAG, "%s ", str);
 
    rxBuffer++;        
    
    if ((strcmp(SET_RATIO_BLINK_HEADER,str)) == 0) {
        setRatio(readHex(stringToString(str,rxBuffer,2)));
        if (CPU_LED_INTERFACE_DEBUG) ESP_LOGE(TAG, "%s ", str);
    }
    else if ((strcmp(SET_TIME_BLINK_HEADER,str)) == 0) {
        //setTimeBlink(readHex(stringToString(str,rxBuffer,4)));
        if (CPU_LED_INTERFACE_DEBUG) ESP_LOGE(TAG, "%s ", str);
    }
    else if ((strcmp(SET_CPU_LED_HEADER,str)) == 0) {
        setCpuLed(readHex(stringToString(str,rxBuffer,2)));
        if (CPU_LED_INTERFACE_DEBUG) ESP_LOGE(TAG, "%s ", str);
    }
    else if ((strcmp(GET_CPU_LED_HEADER,str)) == 0) {
        bool s_led_state;
        if (getCpuLed()){
            s_led_state = true;
        }
        else {
            s_led_state = false;
        }
        if (CPU_LED_INTERFACE_DEBUG) ESP_LOGE(TAG, "LED Status : %s", s_led_state == true ? "ON" : "OFF");

        sprintf (status,"%02d", s_led_state );        
            
        // Write data back to the UART
        uart_write_bytes(COMMAND_UART_PORT_NUM, status, strlen(status));
        status [0] = LF;
        status [1] = '\0';

        uart_write_bytes(COMMAND_UART_PORT_NUM, status, strlen(status));
    }
    else {
        ESP_LOGE(TAG, "Bad command");
    }
}