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

void configure_led(void){

    initCpuLed();

    ESP_LOGI(TAG_CPU_LED, "Cpu Led configured to blink GPIO LED!");
    gpio_reset_pin(getLedGpio(led1, LED_GREEN));
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(getLedGpio(led1, LED_GREEN), GPIO_MODE_OUTPUT);

    setTimeBlink(getLedPeriod(led1,LED_GREEN));
    setRatioBlink(getLedRatio(led1,LED_GREEN));
}

void blinkCpuLed(uint8_t led,uint8_t color, uint32_t time, uint32_t ratio){



    //ESP_LOGI(TAG_CPU_LED, "Turning the LED %s!", s_led1_red_state == true ? "ON" : "OFF");
    /* Toggle the LED state */
    led1.Green.status = !led1.Green.status;
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(getLedGpio(led1, LED_GREEN), getLedStatus(led1, LED_GREEN));

    if (led1.Green.status) vTaskDelay(pdMS_TO_TICKS(time * ratio /100));
    else vTaskDelay(pdMS_TO_TICKS(time - (time * ratio /100)));
}

void setBlueLed(uint8_t ledStatus){
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