/*
 ============================================================================
 Author      : Hassan_Attia
 Description :
 ============================================================================
 */

#include "state.h"
#include "US.h"
#include "CA.h"
#include "DC_Motor.h"




void setup(){

//init all drivers
//init IRQ.....
//init HAL US_DRIVER DC_Driver
//init blocks if any
void DC_MOTOR__init();
void US_init();
//set states pointer for each block
P_CA_STATE = STATE_CA_Waiting;
P_US_STATE = STATE_US_Busy;
P_DC_Motor_STATE = STATE_DC_MOTOR_Idle;



}








int main (){


volatile int delay;

setup();

while(1){

    //Call State for each Module
    P_US_STATE();
    P_CA_STATE();
    P_DC_Motor_STATE();
    //Delay
    for(delay = 0 ; delay< 1000; delay++);

}



return 0;





}


