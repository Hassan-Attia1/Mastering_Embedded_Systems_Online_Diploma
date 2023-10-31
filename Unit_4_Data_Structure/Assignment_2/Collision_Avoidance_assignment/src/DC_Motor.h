/*
 * DC_Motor.h
 *
 *  Created on: Oct 30, 2023
 *      Author: hassan
 */

#ifndef DC_MOTOR_
#define DC_MOTOR_


//Libraries
#include "state.h"




//DC Motor States enumeration

enum{

DC_idle,
DC_busy


}DC_MOTOR_state;

//Pointer to function
 extern void(*P_DC_Motor_STATE)();

//DC Motor initialization
void DC_init();

//DC Motor State Functions
STATE_define(DC_MOTOR_Idle);
STATE_define(DC_MOTOR_Busy);


#endif // DC_MOTOR_
