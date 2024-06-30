/*
 * segment.h
 *
 *  Created on: Mar 7, 2024
 *      Author: hassa
 */

#ifndef SEVEN_SEGMENT_SEGMENT_H_
#define SEVEN_SEGMENT_SEGMENT_H_



#include "stdlib.h"
#include "stdint.h"
#include "stm32_F103C6_gpio_driver.h"
#include "stm32f103x6.h"

#define ZERO 		0xC0
#define ONE  		0xF9
#define TWO	 		0xA4
#define THREE 		0xB0
#define FOUR		0x99
#define FIVE		0x92
#define SIX 		0x82
#define SEVEN		0xF8
#define EIGHT		0x80
#define NINE		0x90

#define Segment_Port	GPIOB


//Segment Functions

void Segement_Init(void);


//array to display number on seven segment


#endif /* SEVEN_SEGMENT_SEGMENT_H_ */
