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
//      xTaskCreate(babysharkTask, "BabyShark", 100, (void *)BUZZER, 1, NULL);
  xTaskCreate(runGreenLed, "greenLED", 50, NULL, 1, NULL);
	xTaskCreate(runRedLed, "redLED", 50, NULL, 1, NULL);
	  xTaskCreate(movementTask, "movementtask", 50, NULL, 3, NULL);

	xTaskCreate(bluetoothReceive, "bluetooth", 100, NULL, 2, NULL);
	vTaskStartScheduler();
}


void loop()
{
}
