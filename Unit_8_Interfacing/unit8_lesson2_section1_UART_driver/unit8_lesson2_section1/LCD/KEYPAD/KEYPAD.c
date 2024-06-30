/*
 * KEYPAD.c
 *
 * Created: 2/7/2024 2:11:32 PM
 *  Author: hassa
 */ 




#include "KEYPAD.h"



int KEYPAD_R [4] = {R0,R1,R2,R3};
int KEYPAD_C [4]=  {C0,C1,C2,C3};


void KEYPAD_init(void){
	
	
	KEYPAD_DataDir_PORTD &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));
	KEYPAD_DataDir_PORTD |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
	
	KEYPAD_PORTD |= 0xFF;
	
	
	
}


char KEYPAD_GETCHAR(){
	int i;
	int j;
	
	for(i=0 ; i<4 ; i++){
		//Turning on all columns 
		KEYPAD_PORTD |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
		//Turning off each column to check which (button/number) pressed
		KEYPAD_PORTD &= ~(1<<KEYPAD_C[i]);
		
		//checking which button is pressed by looping on each Row		
		for( j = 0 ; j < 4 ; j++ ){
			
			
			
			if( !(KEYPAD_READ & (1<<KEYPAD_R[j]) )){
				
				//For single Press
				while(!(KEYPAD_READ & (1<<KEYPAD_R[j]) )){}
				
				switch(i){
					
					case 0 :
					if(j == 0){return '7';}
					else if(j == 1){return '4';}
					else if(j == 2){return '1';}
					else if(j == 3){return '!';}
					
					break;
					
					case 1 :
					if(j == 0){return '8';}
					else if(j == 1){return '5';}
					else if(j == 2){return '2';}
					else if(j == 3){return '0';}
					break;
					
					case 2 :
					if(j == 0){return '9';}
					else if(j == 1){return '6';}
					else if(j == 2){return '3';}
					else if(j == 3){return '=';}
					break;
					
					case 3 :
					if(j == 0){return '/';}
					else if(j == 1){return '*';}
					else if(j == 2){return '-';}
					else if(j == 3){return '+';}
					break;
					
									}
											}
														}
																	}
		
		
		
		//IF user didn't press on any button
		return 'N';
		
		
	}


					 