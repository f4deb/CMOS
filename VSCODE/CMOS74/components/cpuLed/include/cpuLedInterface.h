#ifndef CPU_LED_INTERFACE_H
#define CPU_LED_INTERFACE_H

#include "../../charUtils/include/charUtils.h"

#define CPU_LED_INTERFACE_DEBUG 0

#define CPU_LED_INTERFACE_HEADER "bl"
#define CPU_LED_INTERFACE_HEADER_SIZE 2


#define CPU_LED_INTERFACE_COMMAND_SIZE 1
#define SET_TIME_BLINK_HEADER "t"
#define SET_RATIO_BLINK_HEADER "b"

#define BLINK_CPU_LED "l"


#define SET_CPU_LED_HEADER "w"
#define GET_CPU_LED_HEADER "r"

void cpuLedInterface(char rxBuffer[50]);

#endif