idf_component_register(SRCS "device.c" "deviceInterface.c" "deviceList.c" "transmitMode.c"
                     INCLUDE_DIRS "include"
                    "$ENV{IDF_PATH}/components/esp_event/include")
