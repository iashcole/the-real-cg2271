/*
 * motor.h
 *
 *  Created on: 17 Apr 2019
 *      Author: teo_a
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

extern QueueHandle_t xCommandQueue;
extern TaskHandle_t xBBShandle;
void movementTask(void *);


#endif /* MOVEMENT_H_ */
