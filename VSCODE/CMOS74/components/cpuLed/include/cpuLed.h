#ifndef CPU_LED_H
#define CPU_LED_H

#include <stdint.h>

#define CPU_LED_DEBUG 0

#define LED1_RED_GPIO CONFIG_LED1_RED_GPIO
#define LED1_GREEN_GPIO CONFIG_LED1_GREEN_GPIO

uint32_t getTimeBlink (void);
uint32_t getRatioBlink (void);
void setTimeBlink (uint32_t value);
void setRatioBlink (uint32_t value);

void configure_led(void);
void blinkBlueLed(uint32_t time, uint32_t ratio);
void setBlueLed(uint8_t ledStatus);
uint8_t getBlueLed(void);

#endif