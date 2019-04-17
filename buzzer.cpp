/*
 * buzzer.cpp
 *
 *  Created on: 17 Apr 2019
 *      Author: teo_a
 */
#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>

#include "constant.h"


void sequence() {
	tone(BUZZER,G4,E_SHARK);
	vTaskDelay(1+E_SHARK);
	tone(BUZZER,G4,E_SHARK);
	vTaskDelay(1+E_SHARK);

	tone(BUZZER,G4,E_SHARK);
	vTaskDelay(1+E_SHARK);
	tone(BUZZER,G4,S_SHARK);
	vTaskDelay(1+S_SHARK);
	tone(BUZZER,G4,E_SHARK);
	vTaskDelay(1+E_SHARK);

	tone(BUZZER,G4,S_SHARK);
	vTaskDelay(1+S_SHARK);
	tone(BUZZER,G4,E_SHARK);
	vTaskDelay(1+E_SHARK);
}


void babysharkTask(void* p) {
	for (;;) {

//		if(xSemaphoreTake(xSemaphoreMusic, portMAX_DELAY)) {
		tone(BUZZER,D3,Q_SHARK);
		vTaskDelay(1+Q_SHARK);
		tone(BUZZER,E3,Q_SHARK);
		vTaskDelay(1+Q_SHARK);

		sequence();

		tone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);
		tone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);

		sequence();

		tone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);
		tone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);

		sequence();

		tone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);
		tone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);
		tone(BUZZER,Gb4,H_SHARK);
		vTaskDelay(1+H_SHARK);
//		xSemaphoreGive(xSemaphoreMusic);
//		}

	}
}



