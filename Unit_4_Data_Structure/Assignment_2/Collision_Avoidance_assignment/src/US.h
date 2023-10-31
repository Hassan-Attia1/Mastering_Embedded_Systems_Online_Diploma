/*
 * US.h
 *
 *  Created on: Oct 30, 2023
 *      Author: hassan
 */

#ifndef US_H_
#define US_H_

//Libraries
#include "state.h"


//Ultra Sonic States enumeration

enum{

US_busy


}US_state;


//Ultra Sonic init prototype
void US_init();

//Ultra sonic State Functions prototype

STATE_define(US_Busy);

//Pointer to function
extern void(*P_US_STATE)();


#endif // US_H_


