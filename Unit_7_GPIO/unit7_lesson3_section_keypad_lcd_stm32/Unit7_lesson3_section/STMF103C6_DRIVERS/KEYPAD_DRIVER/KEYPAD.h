/*
 * KEYPAD.h
 *
 * Created: 2/7/2024 2:11:17 PM
 *  Author: hassan
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_



#include "stdlib.h"
#include "stdint.h"
#include "stm32_F103C6_gpio_driver.h"
#include "stm32f103x6.h"

#define KEYPAD_PORTB GPIOB
#define KEYPAD_DataDir_PORTB GPIOB




//ROWS
#define  R0 GPIO_PINS_0
#define  R1 GPIO_PINS_1
#define  R2 GPIO_PINS_3
#define  R3 GPIO_PINS_4
//Columns
#define  C0 GPIO_PINS_5
#define  C1 GPIO_PINS_6
#define  C2 GPIO_PINS_7
#define  C3 GPIO_PINS_8



//KEYPAD FUNCTIONS

void KEYPAD_init(void);
char KEYPAD_GETCHAR();


#endif // KEYPAD_H_

