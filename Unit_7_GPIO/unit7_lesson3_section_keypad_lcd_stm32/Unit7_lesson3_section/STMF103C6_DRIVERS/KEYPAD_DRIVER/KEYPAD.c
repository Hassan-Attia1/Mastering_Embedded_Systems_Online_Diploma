/*
 * KEYPAD.c
 *
 * Created: 2/7/2024 2:11:32 PM
 *  Author: hassa
 */ 





#include "KEYPAD.h"

void wait_msk(uint32_t time){


	uint32_t i,j;
	for(i=0 ;i<time;i++){

		for(j=0;j<255;j++);

	}

}


int KEYPAD_R [] = {GPIO_PINS_0,GPIO_PINS_1,GPIO_PINS_3,GPIO_PINS_4};
int KEYPAD_C []=  {GPIO_PINS_5,GPIO_PINS_6,GPIO_PINS_7,GPIO_PINS_8};

GPIO_PinConfig_t keypad;
void KEYPAD_init(void){


	//	KEYPAD_DataDir_PORTD &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));
	//KEYPAD_DataDir_PORTD |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));

	//KEYPAD_PORTD |= 0xFF;


	//Rows (B0,B1,B3,B4)
	//configuring higher pins(Rows) in keypad as Input(PULL-UP)

	//	int i = 0;

	/*
	keypadpinCfg.GPIO_PinNumber = KEYPAD_R[0];
	keypadpinCfg.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
	MCAL_GPIO_INIT(KEYPAD_DataDir_PORTB, &keypadpinCfg);


	keypadpinCfg.GPIO_PinNumber = KEYPAD_R[1];
	keypadpinCfg.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
	MCAL_GPIO_INIT(KEYPAD_DataDir_PORTB, &keypadpinCfg);
	keypadpinCfg.GPIO_PinNumber = KEYPAD_R[2];
	keypadpinCfg.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
	MCAL_GPIO_INIT(KEYPAD_DataDir_PORTB, &keypadpinCfg);

	keypadpinCfg.GPIO_PinNumber = KEYPAD_R[3];
	keypadpinCfg.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
	MCAL_GPIO_INIT(KEYPAD_DataDir_PORTB, &keypadpinCfg);


	//columns(B5,B6,B7,B8)
			//configuring lower pins(columns) in keypad as output(PUSH_PULL)

	keypadpinCfg.GPIO_PinNumber = KEYPAD_C[0];
	keypadpinCfg.GPIO_PinNumber = GPIO_CONFIG_Output_PP;
	keypadpinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(KEYPAD_DataDir_PORTB, &keypadpinCfg);


	keypadpinCfg.GPIO_PinNumber = KEYPAD_C[1];
	keypadpinCfg.GPIO_PinNumber = GPIO_CONFIG_Output_PP;
	keypadpinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(KEYPAD_DataDir_PORTB, &keypadpinCfg);

	keypadpinCfg.GPIO_PinNumber = KEYPAD_C[2];
	keypadpinCfg.GPIO_PinNumber = GPIO_CONFIG_Output_PP;
	keypadpinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(KEYPAD_DataDir_PORTB, &keypadpinCfg);

	keypadpinCfg.GPIO_PinNumber = KEYPAD_C[3];
	keypadpinCfg.GPIO_PinNumber = GPIO_CONFIG_Output_PP;
	keypadpinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(KEYPAD_DataDir_PORTB, &keypadpinCfg);

	//set columns  high


	MCAL_GPIO_WritePin(KEYPAD_PORTB, KEYPAD_C[0] , GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORTB, KEYPAD_C[1] , GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORTB, KEYPAD_C[2] , GPIO_PIN_SET);
	MCAL_GPIO_WritePin(KEYPAD_PORTB, KEYPAD_C[3] , GPIO_PIN_SET);

	 */

	keypad.GPIO_PinNumber = GPIO_PINS_0;
	keypad.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	keypad.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOB, &keypad);

	keypad.GPIO_PinNumber = GPIO_PINS_1;
	keypad.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	keypad.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOB, &keypad);

	keypad.GPIO_PinNumber = GPIO_PINS_3;
	keypad.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	keypad.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOB, &keypad);

	keypad.GPIO_PinNumber = GPIO_PINS_4;
	keypad.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	keypad.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOB, &keypad);

	keypad.GPIO_PinNumber = GPIO_PINS_5;
	keypad.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	keypad.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOB, &keypad);

	keypad.GPIO_PinNumber = GPIO_PINS_6;
	keypad.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	keypad.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOB, &keypad);

	keypad.GPIO_PinNumber = GPIO_PINS_7;
	keypad.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	keypad.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOB, &keypad);
	keypad.GPIO_PinNumber = GPIO_PINS_8;
	keypad.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	keypad.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOB, &keypad);


	MCAL_GPIO_WritePort(GPIOB, (0xff<<0));

	/*	 MCAL_GPIO_WritePin(GPIOB, GPIO_PINS_5 , GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB, GPIO_PINS_6 , GPIO_PIN_SET);

		MCAL_GPIO_WritePin(GPIOB, GPIO_PINS_7 , GPIO_PIN_SET);
		MCAL_GPIO_WritePin(GPIOB, GPIO_PINS_8 , GPIO_PIN_SET);*/
}


char KEYPAD_GETCHAR(){

	unsigned char i = 0 , j = 0 , k = 0;

	for(i=0 ; i<4 ; i++){
		//Turning on all columns
		//KEYPAD_PORTD |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
		for(k = 0 ; k<4 ; k++ ){
			MCAL_GPIO_WritePin(KEYPAD_PORTB, KEYPAD_C[k], GPIO_PIN_SET);
			wait_msk(5);
		}

		//Turning off each column to check which (button/number) pressed
		MCAL_GPIO_WritePin(KEYPAD_PORTB, KEYPAD_C[i], GPIO_PIN_RESET);
		wait_msk(5);
		//KEYPAD_PORTD &= ~(1<<KEYPAD_C[i]);


		//checking which button pressed by looping on each Row
		for( j = 0 ; j < 4 ; j++ ){



			if(  MCAL_GPIO_ReadPin(KEYPAD_PORTB, KEYPAD_R[j]) == 0)
			{

				//For single Press
				 while(MCAL_GPIO_ReadPin(KEYPAD_PORTB, KEYPAD_R[j]) == 0){}

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




