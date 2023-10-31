/*
 * CA.h
 *
 *  Created on: Oct 30, 2023
 *      Author: hassan
 */
#ifndef CA_H_
#define CA_H_

//Libraries
#include "state.h"



//collision avoidance States enumeration

enum{

CA_waiting,
CA_driving


}CA_state;

//Collision Avoidance init prototype
void CA_init();


//Collision Avoidance STATE function
STATE_define(CA_Waiting);
STATE_define(CA_Driving);

//Pointer to function
 extern void(*P_CA_STATE)();

#endif // CA_H_
