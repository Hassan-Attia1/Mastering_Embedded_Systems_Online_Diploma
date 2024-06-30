//Hassan Attia


#include "stm32_F103C6_gpio_driver.h"
#include "stm32f103x6.h"

void GPIO_init(void){


	GPIO_PinConfig_t pinCfg;



	/*
 	 //setting pin A1 to act as floating input pin
 		pinCfg.GPIO_PinNumber = GPIO_PINS_1;
 		pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
 		MCAL_GPIO_INIT(GPIOA, &pinCfg);

 		//setting pin A13 to act as floating input pin
 		pinCfg.GPIO_PinNumber = GPIO_PINS_13;
 		pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
 		MCAL_GPIO_INIT(GPIOA, &pinCfg);

 		//setting pin B1 to act as output(PULL) pin
 		pinCfg.GPIO_PinNumber = GPIO_PINS_1;
 		pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
 		pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
 		MCAL_GPIO_INIT(GPIOB, &pinCfg);

 		//setting pin B13 to act as output(PULL) pin

 		 pinCfg.GPIO_PinNumber = GPIO_PINS_13;
 		 pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
 		 pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
 		 MCAL_GPIO_INIT(GPIOB, &pinCfg);


	 */

	pinCfg.GPIO_PinNumber = GPIO_PINS_0;
	pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
	MCAL_GPIO_INIT(GPIOA, &pinCfg);

	pinCfg.GPIO_PinNumber = GPIO_PINS_1;
	pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Input_PD;
	MCAL_GPIO_INIT(GPIOA, &pinCfg);

	pinCfg.GPIO_PinNumber = GPIO_PINS_2;
	pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Input_PU;
	MCAL_GPIO_INIT(GPIOA, &pinCfg);

	pinCfg.GPIO_PinNumber = GPIO_PINS_3;
	pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Analog;
	MCAL_GPIO_INIT(GPIOA, &pinCfg);



}


void wait(int x){

	unsigned int i , j;

	for(i = 0 ; i<x ; i++){

		for(j = 0 ; j<255 ; j++);
	}




}


void clock_init(void){


	//enabling clock for GPIO port A

	RCC_GPIOA_CLK_EN();
	//RCC_APB2ENR |= (1 << 2);
	//enabling clock for GPIO port B
	RCC_GPIOB_CLK_EN();
	//RCC_APB2ENR |= (1 << 3);



}

int main(void)
{
	clock_init();
	GPIO_init();

	/*
	while(1){

		if(  MCAL_GPIO_ReadPin(GPIOA, GPIO_PINS_1) == 0 )
		{

			//Toggling on LED 1  at pinB1 (single press)
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PINS_1);
			//GPIOB_ODR ^= 1 << 1;

			while( MCAL_GPIO_ReadPin(GPIOA, GPIO_PINS_1) == 0  );

		}



		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PINS_13) == 1 )
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PINS_13);
			//Toggling on LED 2 at pinB13 (MUltiple press)
			//GPIOB_ODR ^= 1 << 13;


		}

		wait(1);


	}

	 */
while(1){};



	return 0;

}


