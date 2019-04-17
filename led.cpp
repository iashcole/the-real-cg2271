/*
 * led.cpp
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
#include "movement.h"

QueueHandle_t xQueueRed = xQueueCreate(1, sizeof(bool));
QueueHandle_t xQueueGreen = xQueueCreate(1, sizeof(bool));
SemaphoreHandle_t xSemaphoreGreen = xSemaphoreCreateBinary();
SemaphoreHandle_t xSemaphoreRed = xSemaphoreCreateBinary();


void updateShiftRegister(byte leds)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void runGreenLed(void *p){
  int i=0;
  byte leds = 0;
  bool isMoving = false;
  while(1)
  {
    if(xQueueReceive(xQueueGreen, &isMoving, (TickType_t) 0)) {

  if(xSemaphoreTake(xSemaphoreGreen, portMAX_DELAY) == pdTRUE) {
      	  leds = 0;
          updateShiftRegister(leds);
          vTaskDelay(200);
          for (i=0;i<8 && isMoving; ++i){
			  leds = 1;
			  leds = leds << i;
			  updateShiftRegister(leds);
			  vTaskDelay(50);
			  xQueueReceive(xQueueGreen, &isMoving, (TickType_t) 0);
          }
          for (i=0;i<8 && isMoving; ++i){
			  leds = 10000000;
			  leds = leds >> i;
			  updateShiftRegister(leds);
			  vTaskDelay(50);
			  xQueueReceive(xQueueGreen, &isMoving, (TickType_t) 0);
          }
          if(isMoving) {
        	  xQueueOverwrite(xQueueGreen, &isMoving);
          }
          xSemaphoreGive(xSemaphoreGreen);

        }
      } else {
    	  if(xSemaphoreTake(xSemaphoreGreen, portMAX_DELAY) == pdTRUE) {
				leds = 255;
				updateShiftRegister(leds);
				vTaskDelay(200);
				xSemaphoreGive(xSemaphoreGreen);
			}
      }
    }
}
void runRedLed(void *p) {
  bool isMoving=false;
  int delay=250;
  while(1)
  {
    if(xQueueReceive(xQueueRed, &isMoving, (TickType_t) 0)) {
      if(isMoving == true) {
        delay = 500;
      }
        else {
        delay = 250;
      }
    }
    // When stationery
    if(xSemaphoreTake(xSemaphoreRed, portMAX_DELAY) == pdTRUE) {
      digitalWrite(red, HIGH);
      vTaskDelay(delay);
      digitalWrite(red, LOW);
      vTaskDelay(delay);

//      tone(BUZZER,D3,Q_SHARK);
//      		vTaskDelay(1+Q_SHARK);
//      		tone(BUZZER,E3,Q_SHARK);
//      		vTaskDelay(1+Q_SHARK);

//  	tone(BUZZER,G3,E);
//  	vTaskDelay(1+E); //delay duration should always be 1 ms more than the note in order to separate them.
//  	tone(BUZZER,C4,E);
//  	vTaskDelay(1+E);
//  	tone(BUZZER,E4,E);
//  	vTaskDelay(1+E);
//  	tone(BUZZER,G5,Q);
//  	vTaskDelay(1+Q);

      xSemaphoreGive(xSemaphoreRed);
    }
  }
}
