/***************************BLUETOOTH CONTROLLED CAR CODE**************************/
#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>

#include "constant.h"
#include "led.h"
#include "movement.h"

SemaphoreHandle_t xSemaphoreMusic = xSemaphoreCreateBinary();


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



void bluetoothReceive(void *p)
{
  char val;
  TickType_t xLastWakeTime=0;
  while(1){
  if(Serial.available()) {
  //check whether arduino is reciving signal or not
    val = Serial.read();//reads the signal

    Serial.print(val);
    xQueueSend(xCommandQueue, &val, (TickType_t) 0);
      Serial.flush();
      }
  vTaskDelayUntil(&xLastWakeTime, 50);
  }
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

void setup()
{
  //initialize the mode of the pins
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
   pinMode(rm1,OUTPUT);
   pinMode(rm2,OUTPUT);
   pinMode(horn,OUTPUT);
   pinMode(red, OUTPUT);
  //initialize shift registers
   pinMode(latchPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   //set the serial communication rate
  Serial.begin(9600);
      xTaskCreate(babysharkTask, "BabyShark", 100, (void *)BUZZER, 3, NULL);
  xTaskCreate(runGreenLed, "greenLED", 50, NULL, 1, NULL);
	xTaskCreate(runRedLed, "redLED", 50, NULL, 1, NULL);
	  xTaskCreate(movementTask, "movementtask", 50, NULL, 5, NULL);

	xTaskCreate(bluetoothReceive, "bluetooth", 100, NULL, 4, NULL);


  xSemaphoreGive(xSemaphoreMusic);
	vTaskStartScheduler();
}


void loop()
{
}
