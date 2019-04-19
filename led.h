/*
 * led.h
 *
 *  Created on: 17 Apr 2019
 *      Author: teo_a
 */

#ifndef LED_H_
#define LED_H_

extern QueueHandle_t xQueueLed;
extern SemaphoreHandle_t xSemaphoreLed;

void tLED(void *);

void updateShiftRegister(byte);

#endif /* LED_H_ */
