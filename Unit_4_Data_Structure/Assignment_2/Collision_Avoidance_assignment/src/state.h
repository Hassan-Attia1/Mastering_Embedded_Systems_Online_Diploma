/*
 * state.h
 *
 *  Created on: Oct 30, 2023
 *      Author: hassanhttps://www.youtube.com/watch?v=EjuXQy1Iia8
 */

#ifndef STATE_H_
#define STATE_H_


 //Libraries
#include "state.h"
#include "stdio.h"
#include "stdlib.h"





//State Function Declaration Macros
#define STATE_define(_FUNCTION_) void STATE_##_FUNCTION_()
#define STATE(_FUNCTION_) STATE_##_FUNCTION_



//useful functions
int US_Get_distance_random (int l, int r, int count);

//State Connections wires(interface)
//these connections are the interface between each module and the other
//Definitions are in destination i.e CA module & DC module
void Us_set_distance(int distance);// OUT: ultra sonic  ... IN: collision avoidance
void DC_get_speed(int speed);//OUT: collision avoidance ... IN: DC motor

#endif // STATE_H_
