idf_component_register(SRCS "cpuLed.c" "cpuLedDevice.c" "cpuLedDeviceInterface.c" "../charUtils/charUtils.c" "../uartCommand/uartCommand.c"
                        INCLUDE_DIRS "include" 
                        "../device/include"
                        "../charUtils/include" 
                        "../uartCommand/include"
                        "$ENV{IDF_PATH}/components/esp_event/include"
                        "$ENV{IDF_PATH}/components/esp_driver_gpio/include")