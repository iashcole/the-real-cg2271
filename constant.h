/*
 * constant.h
 *
 *  Created on: 17 Apr 2019
 *      Author: teo_a
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_

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

#define BPM 120      // tempo
#define H 2*Q        // half 2/4
#define Q 60000/BPM  // quarter 1/4
#define E Q/2        // eighth 1/8
#define S Q/4        // sixteenth 1/16
#define W 4*Q        // whole 4/4

#define BPM_SHARK 100
#define H_SHARK 2*Q_SHARK        // half 2/4
#define Q_SHARK 60000/BPM_SHARK  // quarter 1/4
#define E_SHARK Q_SHARK/2        // eighth 1/8
#define S_SHARK Q_SHARK/4        // sixteenth 1/16
#define W_SHARK 4*Q_SHARK        // whole 4/4

//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 12; //green
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 13; //orange
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 11; //blue

//Declare the arduino pins
const int horn = 7; //buzzer
const int lm1 = 10; //left motor f
const int lm2 = 9;  //left motor r
const int rm1 = 6;  //right motor f 8
const int rm2 = 5; //right motor r 7
const int red = 8; //red leds 6
const int BUZZER = 2;

#endif /* CONSTANT_H_ */
