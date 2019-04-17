/*
 * led.h
 *
 *  Created on: 17 Apr 2019
 *      Author: teo_a
 */

#ifndef LED_H_
#define LED_H_

extern QueueHandle_t xQueueRed;
extern QueueHandle_t xQueueGreen;
extern SemaphoreHandle_t xSemaphoreGreen;
extern SemaphoreHandle_t xSemaphoreRed;

void runGreenLed(void *);
void runRedLed(void *);
void updateShiftRegister(byte);



#endif /* LED_H_ */
