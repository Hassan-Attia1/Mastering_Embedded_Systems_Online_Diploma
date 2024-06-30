//Hassan Attia



void wait(int x){

	unsigned int i , j;

	for(i = 0 ; i<x ; i++){

		for(j = 0 ; j<255 ; j++);
	}

}


#include "stm32_F103C6_gpio_driver.h"
#include "stm32f103x6.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "segment.h"


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
	//Init Fuctions
	clock_init();
	LCD_Init();
	Segement_Init();
	//Greeting Message
	Write_String("hi there") ;
	wait_ms(500);
	LCD_clear_screen();





	//Code for (Seven-segment & LCD) Test
	unsigned char seven_segment_common_anonde [] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO};
	unsigned char LCD_numbers_test [] = {'0','1','2','3','4','5','6','7','8','9','0'};
	unsigned char counter;

	for(counter = 0; counter<11 ; counter++)
	{
		MCAL_GPIO_WritePort(Segment_Port, ((seven_segment_common_anonde[counter]) << 9) );

		Write_char(LCD_numbers_test[counter]);

		wait(1000);
	}

	LCD_clear_screen();






	// KEYPAD_init();
	KEYPAD_init();
	Write_String("KEYBAD is READY") ;
	wait_ms(500);
	LCD_clear_screen();
	unsigned char symbol;
	//KEYPAD CODE
	while(1){


		symbol = KEYPAD_GETCHAR() ;

		switch(symbol){

		case '!':
			LCD_clear_screen();
			break;

		case 'N':
			/*		Write_String("you didn't press !!");

			LCD_clear_screen();
			 */
			break;

		default:

			Write_char(symbol);

			break;


		}



	}


	return 0;

}


