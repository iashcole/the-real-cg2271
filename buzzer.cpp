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
#include "led.h"

void myTone(byte pin, uint16_t frequency, uint16_t duration)
{ // input parameters: Arduino pin number, frequency in Hz, duration in milliseconds
  unsigned long startTime=millis();
  unsigned long halfPeriod= 1000000L/frequency/2;
  pinMode(pin,OUTPUT);
  while (millis()-startTime< duration)
  {
    digitalWrite(pin,HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(pin,LOW);
    delayMicroseconds(halfPeriod);
  }
  pinMode(pin,INPUT);
}

void starttone() {
	myTone(BUZZER,660,100);
	delay(150);
	myTone(BUZZER,660,100);
	delay(300);
	myTone(BUZZER,660,100);
	delay(300);
	myTone(BUZZER,510,100);
	delay(100);
	myTone(BUZZER,660,100);
	delay(300);
	myTone(BUZZER,770,100);
	delay(550);
	myTone(BUZZER,380,100);
	delay(575);
}

void endtone() {
	myTone(BUZZER,660,100);
	delay(150);
	myTone(BUZZER,660,100);
	delay(300);
	myTone(BUZZER,660,100);
	delay(300);
	myTone(BUZZER,510,100);
	delay(100);
	myTone(BUZZER,660,100);
	delay(300);
	myTone(BUZZER,770,100);
	delay(550);
	myTone(BUZZER,380,100);
	delay(575);

	myTone(BUZZER,510,100);
	delay(450);
	myTone(BUZZER,380,100);
	delay(400);
	myTone(BUZZER,320,100);
	delay(500);
	myTone(BUZZER,440,100);
	delay(300);
	myTone(BUZZER,480,80);
	delay(330);
	myTone(BUZZER,450,100);
	delay(150);
	myTone(BUZZER,430,100);
	delay(300);
	myTone(BUZZER,380,100);
	delay(200);
	myTone(BUZZER,660,80);
	delay(200);
	myTone(BUZZER,760,50);
	delay(150);
	myTone(BUZZER,860,100);
	delay(300);
	myTone(BUZZER,700,80);
	delay(150);
	myTone(BUZZER,760,50);
	delay(350);
	myTone(BUZZER,660,80);
	delay(300);
	myTone(BUZZER,520,80);
	delay(150);
	myTone(BUZZER,580,80);
	delay(150);
	myTone(BUZZER,480,80);
	delay(500);

	myTone(BUZZER,510,100);
	delay(450);
	myTone(BUZZER,380,100);
	delay(400);
	myTone(BUZZER,320,100);
	delay(500);
	myTone(BUZZER,440,100);
	delay(300);
	myTone(BUZZER,480,80);
	delay(330);
	myTone(BUZZER,450,100);
	delay(150);
	myTone(BUZZER,430,100);
	delay(300);
	myTone(BUZZER,380,100);
	delay(200);
	myTone(BUZZER,660,80);
	delay(200);
	myTone(BUZZER,760,50);
	delay(150);
	myTone(BUZZER,860,100);
	delay(300);
	myTone(BUZZER,700,80);
	delay(150);
	myTone(BUZZER,760,50);
	delay(350);
	myTone(BUZZER,660,80);
	delay(300);
	myTone(BUZZER,520,80);
	delay(150);
	myTone(BUZZER,580,80);
	delay(150);
	myTone(BUZZER,480,80);
	delay(500);
}

void tAudio(void *p) {
	for (;;) {
		myTone(BUZZER,D3,Q_SHARK);
		vTaskDelay(1+Q_SHARK);
		myTone(BUZZER,E3,Q_SHARK);
		vTaskDelay(1+Q_SHARK);

		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G4,S_SHARK);
		vTaskDelay(1+S_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G4,S_SHARK);
		vTaskDelay(1+S_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G4,S_SHARK);
		vTaskDelay(1+S_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G4,S_SHARK);
		vTaskDelay(1+S_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G4,S_SHARK);
		vTaskDelay(1+S_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G4,S_SHARK);
		vTaskDelay(1+S_SHARK);
		myTone(BUZZER,G4,E_SHARK);
		vTaskDelay(1+E_SHARK);

		myTone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,G3,E_SHARK);
		vTaskDelay(1+E_SHARK);
		myTone(BUZZER,Gb4,H_SHARK);
		vTaskDelay(1+H_SHARK);
	}
}
