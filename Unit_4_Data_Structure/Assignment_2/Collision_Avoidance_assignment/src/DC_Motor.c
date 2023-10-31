/*
 * DC_Motor.c
 *
 *  Created on: Oct 30, 2023
 *      Author: hassan
 */


#include "DC_Motor.h"

void(*P_DC_Motor_STATE)();

 //variables
 int DC_speed =0;



  //DC motor init

void DC_MOTOR__init(){

//init US Driver

printf("\n DC Motor_init...\n");


}


//Interface between CA & DC motor
void DC_get_speed(int speed){
    DC_speed = speed;
    P_DC_Motor_STATE = STATE(DC_MOTOR_Busy);
printf("\nCA-----------------speed = %d----------------->DC\n",DC_speed);
}




STATE_define(DC_MOTOR_Idle){


//STATE NAME
DC_MOTOR_state = DC_idle;



//STATE Action
//Action : change the speed via PWM

printf("\nDC_idle state: speed = %d\n",DC_speed);

}



STATE_define(DC_MOTOR_Busy){


//STATE NAME
DC_MOTOR_state = DC_busy;



//STATE Action
//Action : change the speed via PWM

P_DC_Motor_STATE = STATE(DC_MOTOR_Idle);

printf("\nDC_busy state:  speed = %d \n", DC_speed);

}

