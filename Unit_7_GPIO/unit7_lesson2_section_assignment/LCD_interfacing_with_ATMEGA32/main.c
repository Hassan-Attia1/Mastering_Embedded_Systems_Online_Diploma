/*
 * LCD_interfacing_with_ATMEGA32.c
 *
 * Created: 2/6/2024 7:06:37 AM
 * Author : hassa
 */ 

#include <avr/io.h>
#include "LCD/LCD.h"
#include "LCD/KEYPAD/KEYPAD.h"

int main(void)
{
    LCD_Init();
	KEYPAD_init();
	 
	 char pressed_key ;
	 
	     while (1) 
    {	pressed_key = KEYPAD_GETCHAR();
		switch(pressed_key){
			
			
			case '!':
			LCD_clear_screen();
			break;
			case 'N':
			break;
			default:
			Write_char(pressed_key);
			break;
			
			
			
			
		}
	
	
	
	
		
    }
	
	
	
	
	
}




