/*
 * US.c
 *
 *  Created on: Oct 30, 2023
 *      Author: hassan
 */






#include "US.h"


 void(*P_US_STATE)();

//Variables
int US_distance = 0;



//function definition

void US_init(){

//init US Driver

printf("\n US_init...\n");


}


STATE_define(US_Busy){

//STATE NAME
US_state = US_busy;
//STATE action
//Ultra sonic readings
US_distance = US_Get_distance_random(45,55,1);

Us_set_distance(US_distance);
P_US_STATE = STATE(US_Busy);



}





int US_Get_distance_random (int l, int r, int count){

//this will generate numbers from l to r range


int i;

for (i  = 0; i< count; i++){

    int rand_num = ( rand() % (r - l + 1) ) + l;
    return rand_num ;


}
return 0;
}
