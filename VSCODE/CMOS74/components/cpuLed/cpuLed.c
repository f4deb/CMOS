#include <stdio.h>
#include "cpuLed.h"

#include "sdkconfig.h"

#include "esp_event.h"
#include "esp_log.h"

#include "../charUtils/include/charUtils.h"


#include "../../../../esp-idf/components/esp_driver_gpio/include/driver/gpio.h"


static const char *TAG_CPU_LED = "CPU_LED";

static uint8_t s_led1_red_state = 0;
static uint8_t s_led1_green_state = 0;
static uint8_t s_led2_red_state = 0;
static uint8_t s_led2_green_state = 0;
static uint8_t s_led_state = 0;


static CpuLed led1;
static CpuLed led2;

uint32_t timeBlink ;
uint32_t ratioBlink;

void initCpuLed (void){
    led1.Red.value = LED_RED;
    led1.Green.value = LED_GREEN;
    led1.value = 1;

    led1.Red.status = 0;
    led1.Red.pinNumber = CONFIG_LED1_RED_GPIO;
    led1.Red.period = CONFIG_LED1_RED_PERIOD;
    led1.Red.ratio = CONFIG_LED1_RED_RATIO;

    led1.Green.status = 0;
    led1.Green.pinNumber = CONFIG_LED1_GREEN_GPIO;
    led1.Green.period = CONFIG_LED1_GREEN_PERIOD;
    led1.Green.ratio = CONFIG_LED1_GREEN_RATIO;

    
    
    led2.Red.value = LED_RED;
    led2.Green.value = LED_GREEN;
    led2.value = 1;

    led2.Red.status = 0;
    led2.Red.pinNumber = CONFIG_LED1_RED_GPIO;
    led2.Red.period = CONFIG_LED1_RED_PERIOD;
    led2.Red.ratio = CONFIG_LED1_RED_RATIO;

    led2.Green.status = 0;
    led2.Green.pinNumber = CONFIG_LED1_GREEN_GPIO;
    led2.Green.period = CONFIG_LED1_GREEN_PERIOD;
    led2.Green.ratio = CONFIG_LED1_GREEN_RATIO;

}

uint32_t getTimeBlink (void){
    return timeBlink;
}

uint32_t getRatioBlink (void){
    return ratioBlink;
}

void setTimeBlink (uint32_t value){
    timeBlink = value;
}

void setRatioBlink (uint32_t value){
    ratioBlink = value;
}

uint8_t getLedGpio (CpuLed led,uint8_t color){
    uint8_t result = 0;
        if (color == LED_RED){
            result = led.Red.pinNumber;
        }
        else if (color == LED_GREEN){
            result = led.Green.pinNumber;        
        } 
    return result;
}

uint32_t getLedPeriod(CpuLed led,uint8_t color){
    uint32_t result = 0;
    if (color == LED_RED){
            result = led.Red.period;
        }
        else if (color == LED_GREEN){
            result = led.Green.period;        
        } 
    return result;
}

uint8_t getLedRatio(CpuLed led,uint8_t color){
    uint8_t result = 0;
    if (color == LED_RED){
            result = led.Red.ratio;
        }
        else if (color == LED_GREEN){
            result = led.Green.ratio;        
        } 
    return result;
}

uint8_t getLedStatus(CpuLed led,uint8_t color){
    uint8_t result = 0;
    if (color == LED_RED){
            result = led.Red.status;
        }
        else if (color == LED_GREEN){
            result = led.Green.status;        
        } 
    return result;
}

void setLedStatus (CpuLed led, uint8_t color,uint8_t status) {
        if (color == LED_RED){
            led1.Red.status = status;
        }
        else if (color == LED_GREEN){
            led1.Green.status = status;        
        } 
}

CpuLed getLed1(void){
    return led1;
}

void initLed(CpuLed led, uint8_t color){
    ESP_LOGI(TAG_CPU_LED, "Cpu Led configured to blink GPIO LED!");
    gpio_reset_pin(getLedGpio(led, color));
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(getLedGpio(led, color), GPIO_MODE_OUTPUT);

    setTimeBlink(getLedPeriod(led,color));
    setRatioBlink(getLedRatio(led,color));

    gpio_set_level(getLedGpio(led, color), 1);
}


void configure_led(void){
    initCpuLed();
    initLed(led1,LED_GREEN);
    initLed(led1,LED_RED);
    initLed(led2,LED_GREEN);
    initLed(led2,LED_RED);
}

void blinkCpuLed(CpuLed led, uint8_t color){
    uint8_t status;
    ESP_LOGI(TAG_CPU_LED, "Turning the LED %s!", getLedStatus(led, color) == true ? "OFF" : "ON");

    /* Toggle the LED state */

	//printf("l adresse de led est : %p\n",&led);
	//printf("l adresse de led1 est : %p\n",&led1);

    status = getLedStatus(led, color);
    setLedStatus(led, color, !status);

    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(getLedGpio(led, color), getLedStatus(led, color));

    if (getLedStatus(led,color)) vTaskDelay(pdMS_TO_TICKS(getLedPeriod(led,color) * getLedRatio(led,color) /100));
    else vTaskDelay(pdMS_TO_TICKS(getLedPeriod(led,color) - (getLedPeriod(led,color) * getLedRatio(led,color) /100)));
}

void setBlueLevd(uint8_t ledStatus){
    ESP_LOGI(TAG_CPU_LED, "Turning the LED %s!", ledStatus == true ? "ON" : "OFF");
    /* Toggle the LED state */
    s_led1_red_state = ledStatus;
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(LED1_GREEN_GPIO, s_led1_red_state);
}

uint8_t getBlueLed(void){

    if (CPU_LED_DEBUG) ESP_LOGI(TAG_CPU_LED, "Return the LED Status %s!", s_led1_red_state == true ? "ON" : "OFF");
    return s_led1_red_state;
}