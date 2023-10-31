/*
 * CA.c
 *
 *  Created on: Oct 30, 2023
 *      Author: hassan
 */


#include "CA.h"

//Pointer to function
  void(*P_CA_STATE)();


//variable
int CA_distance = 0;
int CA_speed = 0;
int CA_threshold = 50;



void Us_set_distance(int distance){

CA_distance = distance;

(CA_distance <= CA_threshold)?  (P_CA_STATE = STATE(CA_Waiting) ):(P_CA_STATE = STATE(CA_Driving));
printf("\nUS-----------------distance = %d----------------->CA\n",CA_distance);


}





STATE_define(CA_Waiting){

//STATE NAME
CA_state = CA_waiting;
printf("\nCA_Waiting State: distance = %d   Speed = %d\n",CA_distance,CA_speed);




//STATE Action
 CA_speed = 0;
 DC_get_speed(CA_speed);



}



STATE_define(CA_Driving){

//STATE NAME
CA_state = CA_driving;
printf("\nCA_Driving State: distance = %d   Speed = %d\n",CA_distance,CA_speed);
//STATE Action
CA_speed = 30;
DC_get_speed(CA_speed);


}




