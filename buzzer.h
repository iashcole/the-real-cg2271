/*
 * buzzer.h
 *
 *  Created on: 17 Apr 2019
 *      Author: teo_a
 */

#ifndef BUZZER_H_
#define BUZZER_H_

extern SemaphoreHandle_t xSemaphoreMusic;
extern QueueHandle_t xQueueMusic;

void starttone();
void endtone();
void sequence();
void babysharkTask(void*);

#endif /* BUZZER_H_ */
