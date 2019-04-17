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

#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define LA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define LA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define LA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50

#define NOTE_C4  262   //Defining note frequency
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

#define BPM 120      // tempo
#define H 2*Q        // half 2/4
#define Q 60000/BPM  // quarter 1/4
#define E Q/2        // eighth 1/8
#define S Q/4        // sixteenth 1/16
#define W 4*Q        // whole 4/4

#define BPM_SHARK 240
#define H_SHARK 2*Q_SHARK        // half 2/4
#define Q_SHARK 60000/BPM_SHARK  // quarter 1/4
#define E_SHARK Q_SHARK/2        // eighth 1/8
#define S_SHARK Q_SHARK/4        // sixteenth 1/16
#define W_SHARK 4*Q_SHARK        // whole 4/4

QueueHandle_t xQueueMusic = xQueueCreate(1, sizeof(bool));

SemaphoreHandle_t xSemaphoreMusic = xSemaphoreCreateBinary();


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

//	myTone(BUZZER, G3, E);
//	delay(1 + E); //delay duration should always be 1 ms more than the note in order to separate them.
//	myTone(BUZZER, C4, E);
//	delay(1 + E);
//	myTone(BUZZER, E4, E);
//	delay(1 + E);
//	myTone(BUZZER, G5, Q);
//	delay(1 + Q);
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
//	myTone(BUZZER,G3,E);
//		delay(1+E); //delay duration should always be 1 ms more than the note in order to separate them.
//		myTone(BUZZER,C4,E);
//		delay(1+E);
//		myTone(BUZZER,E4,E);
//		delay(1+E);
//		myTone(BUZZER,G4,E);
//		delay(1+E);
//		myTone(BUZZER,C5,E);
//		delay(1+E);
//		myTone(BUZZER,E5,E);
//		delay(1+E);
//		myTone(BUZZER,G5,Q+E);
//		delay(1+Q+E);
//		myTone(BUZZER,E5,Q+E);
//		delay(1+Q+E);
////
//		myTone(BUZZER,Ab3,E);
//		delay(1+E);
//		myTone(BUZZER,C4,E);
//		delay(1+E);
//		myTone(BUZZER,Eb4,E);
//		delay(1+E);
//		myTone(BUZZER,Ab4,E);
//		delay(1+E);
//		myTone(BUZZER,C5,E);
//		delay(1+E);
//		myTone(BUZZER,Eb5,E);
//		delay(1+E);
//		myTone(BUZZER,Ab5,Q+E);
//		delay(1+Q+E);
//		myTone(BUZZER,Eb5,Q+E);
//		delay(1+Q+E);
//
//		myTone(BUZZER,Bb3,E);
//		delay(1+E);
//		myTone(BUZZER,D4,E);
//		delay(1+E);
//		myTone(BUZZER,F4,E);
//		delay(1+E);
//		myTone(BUZZER,Bb4,E);
//		delay(1+E);
//		myTone(BUZZER,D5,E);
//		delay(1+E);
//		myTone(BUZZER,F5,E);
//		delay(1+E);
//		myTone(BUZZER,Bb5,Q+E);
//		delay(1+Q+E);
//		myTone(BUZZER,Bb5,E);
//		delay(1+E);
//		myTone(BUZZER,Bb5,E);
//		delay(1+E);
//		myTone(BUZZER,Bb5,E);
//		delay(1+E);
//		myTone(BUZZER,C6,H+Q+E);
//		delay(1+H+Q+E);
//
//		delay(2*H);

	myTone(9,660,100);
	delay(150);
	myTone(9,660,100);
	delay(300);
	myTone(9,660,100);
	delay(300);
	myTone(9,510,100);
	delay(100);
	myTone(9,660,100);
	delay(300);
	myTone(9,770,100);
	delay(550);
	myTone(9,380,100);
	delay(575);

	myTone(9,510,100);
	delay(450);
	myTone(9,380,100);
	delay(400);
	myTone(9,320,100);
	delay(500);
	myTone(9,440,100);
	delay(300);
	myTone(9,480,80);
	delay(330);
	myTone(9,450,100);
	delay(150);
	myTone(9,430,100);
	delay(300);
	myTone(9,380,100);
	delay(200);
	myTone(9,660,80);
	delay(200);
	myTone(9,760,50);
	delay(150);
	myTone(9,860,100);
	delay(300);
	myTone(9,700,80);
	delay(150);
	myTone(9,760,50);
	delay(350);
	myTone(9,660,80);
	delay(300);
	myTone(9,520,80);
	delay(150);
	myTone(9,580,80);
	delay(150);
	myTone(9,480,80);
	delay(500);

	myTone(9,510,100);
	delay(450);
	myTone(9,380,100);
	delay(400);
	myTone(9,320,100);
	delay(500);
	myTone(9,440,100);
	delay(300);
	myTone(9,480,80);
	delay(330);
	myTone(9,450,100);
	delay(150);
	myTone(9,430,100);
	delay(300);
	myTone(9,380,100);
	delay(200);
	myTone(9,660,80);
	delay(200);
	myTone(9,760,50);
	delay(150);
	myTone(9,860,100);
	delay(300);
	myTone(9,700,80);
	delay(150);
	myTone(9,760,50);
	delay(350);
	myTone(9,660,80);
	delay(300);
	myTone(9,520,80);
	delay(150);
	myTone(9,580,80);
	delay(150);
	myTone(9,480,80);
	delay(500);

}

void sequence() {
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
}

void babysharkTask(void *p) {
	bool isPlaying;
	for (;;) {
//		if(xQueueReceive(xQueueMusic, &isPlaying, (TickType_t) 0)) {
//		if(xSemaphoreTake(xSemaphoreMusic, portMAX_DELAY)) {
				myTone(BUZZER,D3,Q_SHARK);
				vTaskDelay(1+Q_SHARK);
				myTone(BUZZER,E3,Q_SHARK);
				vTaskDelay(1+Q_SHARK);

				sequence();

				myTone(BUZZER,G3,E_SHARK);
				vTaskDelay(1+E_SHARK);
				myTone(BUZZER,G3,E_SHARK);
				vTaskDelay(1+E_SHARK);

				sequence();

				myTone(BUZZER,G3,E_SHARK);
				vTaskDelay(1+E_SHARK);
				myTone(BUZZER,G3,E_SHARK);
				vTaskDelay(1+E_SHARK);

				sequence();

				myTone(BUZZER,G3,E_SHARK);
				vTaskDelay(1+E_SHARK);
				myTone(BUZZER,G3,E_SHARK);
				vTaskDelay(1+E_SHARK);
				myTone(BUZZER,Gb4,H_SHARK);
				vTaskDelay(1+H_SHARK);
//				xSemaphoreGive(xSemaphoreMusic);
		}
//	}
//	}
}
