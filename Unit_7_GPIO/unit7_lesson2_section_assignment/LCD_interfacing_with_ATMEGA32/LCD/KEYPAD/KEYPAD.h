/*
 * KEYPAD.h
 *
 * Created: 2/7/2024 2:11:17 PM
 *  Author: hassa
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL

#include "avr/io.h"
#include "util/delay.h"


#define KEYPAD_PORTD PORTD
#define KEYPAD_DataDir_PORTD DDRD
#define KEYPAD_READ	PIND
//ROWS
#define  R0 0
#define  R1 1
#define  R2 2
#define  R3 3
//Columns
#define  C0 4
#define  C1 5
#define  C2 6
#define  C3 7



//KEYPAD FUNCTIONS

void KEYPAD_init(void);
char KEYPAD_GETCHAR();


#endif /* KEYPAD_H_ */