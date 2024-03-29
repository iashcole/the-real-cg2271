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
#include "buzzer.h"

void tSerial(void *p)
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

	xTaskCreate(tAudio, "BabyShark", 300, NULL, 1, NULL);
	xTaskCreate(tLED, "greenLED", 100, NULL, 1, NULL);
	xTaskCreate(tMotorControl, "movementtask", 100, NULL, 4, NULL);
	xTaskCreate(tSerial, "bluetooth", 100, NULL, 3, NULL);
	vTaskStartScheduler();
}


void loop()
{
}
