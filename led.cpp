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

QueueHandle_t xQueueLed = xQueueCreate(1, sizeof(bool));
SemaphoreHandle_t xSemaphoreLed = xSemaphoreCreateBinary();

void updateShiftRegister(byte leds)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void tLED(void *p){
  int i=0;
  int count=0;
  byte leds = 0;
  bool state = true, isMoving = false;
  while(1)
  {
    if(xQueueReceive(xQueueLed, &isMoving, (TickType_t) 0)) {

  if(xSemaphoreTake(xSemaphoreLed, portMAX_DELAY) == pdTRUE) {
      	  leds = 0;
          updateShiftRegister(leds);
          vTaskDelay(200);
          for (i=0;i<8 && isMoving; ++i){
			  leds = 1;
			  leds = leds << i;
			  updateShiftRegister(leds);
			  vTaskDelay(62.5);
			  count+= 50;
			  xQueueReceive(xQueueLed, &isMoving, (TickType_t) 0);
          }
          digitalWrite(red, state);
          for (i=0;i<8 && isMoving; ++i){
			  leds = 10000000;
			  leds = leds >> i;
			  updateShiftRegister(leds);
			  vTaskDelay(62.5);
			  xQueueReceive(xQueueLed, &isMoving, (TickType_t) 0);
          }
          digitalWrite(red, !state);
          if(isMoving) {
        	  xQueueOverwrite(xQueueLed, &isMoving);
          }
          xSemaphoreGive(xSemaphoreLed);

        }
      } else {
    	  if(xSemaphoreTake(xSemaphoreLed, portMAX_DELAY) == pdTRUE) {
				leds = 255;
				updateShiftRegister(leds);
				vTaskDelay(200);
				xSemaphoreGive(xSemaphoreLed);

			      digitalWrite(red, state);
			      vTaskDelay(250);
			      digitalWrite(red, !state);
			      vTaskDelay(250);
			}
      }
    }
}
