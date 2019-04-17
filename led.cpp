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

void runLed(void *p){
  int i=0;
  int count=0;
  byte leds = 0;
  bool state = true, isMoving = false;
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
			  vTaskDelay(62.5);
			  count+= 50;
			  xQueueReceive(xQueueGreen, &isMoving, (TickType_t) 0);
//			  if(count%500 == 0) {

//			  }
          }
          digitalWrite(red, state);
          for (i=0;i<8 && isMoving; ++i){
			  leds = 10000000;
			  leds = leds >> i;
			  updateShiftRegister(leds);
			  vTaskDelay(62.5);
			  xQueueReceive(xQueueGreen, &isMoving, (TickType_t) 0);
			  //if(count%500 == 0) {

//			  }
          }
          digitalWrite(red, !state);
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

			      digitalWrite(red, state);
			      vTaskDelay(250);
			      digitalWrite(red, !state);
			      vTaskDelay(250);

			}
      }
    }
}
//void runRedLed(void *p) {
//  bool isMoving=false;
//  TickType_t delay=250;
//  while(1)
//  {
//    if(xQueueReceive(xQueueRed, &isMoving, (TickType_t) 0)) {
//      if(isMoving == true) {
//        delay = 500;
//      }
//        else {
//        delay = 250;
//      }
//    }
//    // When stationery
//    if(xSemaphoreTake(xSemaphoreRed, portMAX_DELAY) == pdTRUE) {
//      digitalWrite(red, HIGH);
//      vTaskDelay(delay);
//      digitalWrite(red, LOW);
//      vTaskDelay(delay);
//      xSemaphoreGive(xSemaphoreRed);
//    }
//  }
//}
