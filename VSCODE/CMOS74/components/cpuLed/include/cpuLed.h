#ifndef CPU_LED_H
#define CPU_LED_H

#include <stdint.h>

#define CPU_LED_DEBUG 0

#define CPU_LED1_RED 0
#define CPU_LED1_GREEN 1
#define CPU_LED2_RED 2
#define CPU_LED2_GREEN 3

#define LED1_RED_GPIO CONFIG_LED1_RED_GPIO
#define LED1_GREEN_GPIO CONFIG_LED1_GREEN_GPIO
#define LED2_RED_GPIO CONFIG_LED2_RED_GPIO
#define LED2_GREEN_GPIO CONFIG_LED2_GREEN_GPIO

void readStatusLed(uint8_t led);
void writeStatusLed(uint8_t led);  


uint32_t getTimeBlink (void);
uint32_t getRatioBlink (void);
void setTimeBlink (uint32_t value);
void setRatioBlink (uint32_t value);

void configure_led(void);
void blinkCpuLed(uint8_t led, uint32_t time, uint32_t ratio);
void setBlueLed(uint8_t ledStatus);
uint8_t getBlueLed(void);

#endif