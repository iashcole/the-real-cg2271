/*
 * movement.cpp
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
#include "buzzer.h"

QueueHandle_t xCommandQueue = xQueueCreate(10, sizeof(char));

void movementTask(void *p)
{
  char val1;
  bool isMoving=false, temp=false;
  int velocity=255;
  byte leds;
  while(1) {
  if (xQueueReceive(xCommandQueue, &val1, (TickType_t) portMAX_DELAY) == pdTRUE) {
    Serial.println(val1);
    Serial.println("does this execute?");
    // Upon start
    if (val1 == 'X')
          {
			for (int i = 0; i < 2; i++) {
				leds = 255;
				updateShiftRegister(leds);
				delay(500);
				leds = 0;
				updateShiftRegister(leds);
				delay(500);
			}
			  xSemaphoreGive(xSemaphoreRed);
    	  	  xSemaphoreGive(xSemaphoreGreen);
//    	  	  temp = true;
//    	  	  xQueueOverwrite(xQueueMusic, &temp);
//    	  	  xSemaphoreGive(xSemaphoreMusic);
    	  	starttone();

          }
    // End, play victory tone
    else if (val1 == 'x')
          {
    		xSemaphoreTake(xSemaphoreRed, portMAX_DELAY);
    		xSemaphoreTake(xSemaphoreGreen, portMAX_DELAY);
    		endtone();
          }
    /*********For Forward motion*********/
    else if (val1 == 'F')
      {
      Serial.println("FORWARD");
      analogWrite(lm1,velocity);  analogWrite(rm1,velocity);
      digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
      isMoving=true;
      xQueueOverwrite(xQueueRed, &isMoving);
      xQueueOverwrite(xQueueGreen, &isMoving);
      }

      /*********For Backward Motion*********/
      else if(val1 == 'B')
      {
      Serial.println("BACK");
        analogWrite(lm2,velocity);  analogWrite(rm2,velocity);
      digitalWrite(lm1,0);       digitalWrite(rm1,0);
      isMoving=true;
      xQueueOverwrite(xQueueRed, &isMoving);
      xQueueOverwrite(xQueueGreen, &isMoving);
      }
       /*********Right*********/
      else if(val1 == 'R')
      {
      Serial.println("RIGHT");
      analogWrite(lm1,velocity);  digitalWrite(rm1,LOW);
      digitalWrite(lm2,LOW);       analogWrite(rm2,velocity);
      isMoving=true;
      xQueueOverwrite(xQueueRed, &isMoving);
      xQueueOverwrite(xQueueGreen, &isMoving);
      }
       /*********Left*********/
      else if(val1 == 'L')
      {
       Serial.println("LEFT");
       digitalWrite(lm1,LOW);  analogWrite(rm1,velocity);
      analogWrite(lm2, velocity);       digitalWrite(rm2,LOW);
      isMoving=true;
      xQueueOverwrite(xQueueRed, &isMoving);
      xQueueOverwrite(xQueueGreen, &isMoving);
      }
        /*********FrontLeft*********/
      else if(val1 == 'G')
      {
       Serial.println("FRONTLEFT");
       analogWrite(lm1,velocity/2);  analogWrite(rm1,velocity);
      digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
      isMoving=true;
      xQueueOverwrite(xQueueRed, &isMoving);
      xQueueOverwrite(xQueueGreen, &isMoving);
      }
        /*********FrontRight*********/
      else if(val1 == 'I')
      {
       Serial.println("FRONTRIGHT");
      analogWrite(lm1,velocity);  analogWrite(rm1,velocity/2);
      digitalWrite(lm2,LOW);   digitalWrite(rm2, LOW);
      isMoving=true;
      xQueueOverwrite(xQueueRed, &isMoving);
      xQueueOverwrite(xQueueGreen, &isMoving);
      }
        /*********BackLeft*********/
      else if(val1 == 'H')
      {
       Serial.println("BACKLEFT");
        analogWrite(lm2,velocity/2);  analogWrite(rm2,velocity);
      digitalWrite(lm1,LOW);     digitalWrite(rm1,LOW);
      isMoving=true;
      xQueueOverwrite(xQueueRed, &isMoving);
      xQueueOverwrite(xQueueGreen, &isMoving);
      }
        /*********BackRight*********/
      else if(val1 == 'J')
      {
       Serial.println("BACKRIGHT");
        analogWrite(lm2,velocity);  analogWrite(rm2,velocity/2);
      digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
      isMoving=true;
      xQueueOverwrite(xQueueRed, &isMoving);
      xQueueOverwrite(xQueueGreen, &isMoving);
      }
       /*********Horn*********/
     else if(val1 == 'V')
      {
      digitalWrite(horn,HIGH);
      }
    else if(val1 == 'v')
      {
      digitalWrite(horn,LOW);
      }
    /*
     * Velocity mode map from 0-10 (11 values total)
     */
    else if(val1 == '0')
      {
    	velocity = 0;
      }
    else if(val1 == '1')
      {
    	velocity = map(1, 0, 10, 0, 255);
      }
    else if(val1 == '2')
      {
    	velocity = map(2, 0, 10, 0, 255);
      }
    else if(val1 == '3')
      {
    	velocity = map(3, 0, 10, 0, 255);
      }
    else if(val1 == '4')
      {
    	velocity = map(4, 0, 10, 0, 255);
      }
    else if(val1 == '5')
      {
    	velocity = map(5, 0, 10, 0, 255);
      }
    else if(val1 == '6')
      {
    	velocity = map(6, 0, 10, 0, 255);
      }
    else if(val1 == '7')
      {
    	velocity = map(7, 0, 10, 0, 255);
      }
    else if(val1 == '8')
      {
    	velocity = map(8, 0, 10, 0, 255);
      }
    else if(val1 == '9')
      {
    	velocity = map(9, 0, 10, 0, 255);
      }
    else if(val1 == 'q')
      {
    	velocity = map(10, 0, 10, 0, 255);
      }
	  /*********STOP*********/
      else if(val1 == 'S')
          {
//          Serial.println("Invalid!!!");
           digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          isMoving=false;
          xQueueOverwrite(xQueueRed, &isMoving);
          xQueueOverwrite(xQueueGreen, &isMoving);
          }
      else {
    	  Serial.print("Invalid command: ");
    	  Serial.println(val1);
      }
      }
  }
}



