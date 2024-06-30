/*
 * LCD.c
 *
 
 * Created: 2/6/2024 7:09:02 AM
 *  Author: hassan
 */ 


#include "LCD.h"
//***************************KICK FUNCTION***********************************
void LCD_KICK(void){
	
	//this function made to disable/enable the read / write mode when we write the intended command in order to avoid any other interrupt command 
		
	
	
	LCD_CTRL_PORTB &= ~(1<<Enable_Switch);
	
	_delay_ms(30);
	
	LCD_CTRL_PORTB |= (1<<Enable_Switch);
	
	
	
	
}

//***************************LCD INIT FUNCTION***********************************

 
void LCD_Init(void)
{
		_delay_ms(20);	
		LCD_Busy();
		LCD_CTRL_dir |= (1<<RS_Switch) | (1<<RW_Switch) | (1<<Enable_Switch);
		LCD_CTRL_PORTB &= ~((1<<RS_Switch) | (1<<RW_Switch) | (1<<Enable_Switch));
		LCD_PORTA_dir = 0xFF;
		LCD_clear_screen();
		
	#ifdef Eight_Bit_MODE

	Write_Command(eight_bit_2Line);
	
	#endif
	

	#ifdef FOUR_Bit_MODE
	LCD_Busy();
	LCD_command_4bit(0x02);
	LCD_command_4bit(four_bit_2line);
 
	#endif
	
	Write_Command(Entry_mode);
	Write_Command(Beginning_first_line);
	Write_Command(Display_on_Curosr_blinking);
	
	
	
}

//***************************LCD CLEAR FUNCTION***********************************

void LCD_clear_screen(void)
{
	Write_Command(Clear_display);
}
 
 
 
 //***************************COMMAND FUNCTION***********************************

void Write_Command(unsigned char command){
	
	
	
	#ifdef Eight_Bit_MODE
	LCD_Busy();
	LCD_PORTA = command; // look at LCD Command Macros & LCD Instruction Set Macros in the header file
	LCD_CTRL_PORTB &= ~((1<<RS_Switch) | (1<<RW_Switch)); 
	LCD_KICK();
	#endif
	
	
	 #ifdef FOUR_BIT_MODE
	 LCD_Busy();
	 LCD_PORTA = (LCD_PORTA & 0x0F)|(command & 0xF0);
	 LCD_CTRL_PORTB &= ~((1<<RS_Switch) | (1<<RW_Switch)); 
 
	 LCD_KICK();
	  
	  LCD_PORTA = (LCD_PORTA & 0x0F)|(command << DATA_SHIFT);
	  LCD_CTRL_PORTB &= ~((1<<RS_Switch) | (1<<RW_Switch));
	 
	  LCD_KICK();
	   
	 
	 #endif
		
	
}

//******************************CHARACTER FUNCTION********************************


void Write_char(unsigned char data){
	
		#ifdef Eight_Bit_MODE
		LCD_Busy();
		LCD_CTRL_PORTB |= (1<<RS_Switch);
		LCD_PORTA = data; // look at LCD Command Macros & LCD Instruction Set Macros in the header file
		LCD_CTRL_PORTB |= (1<<RS_Switch);
		LCD_CTRL_PORTB &= ~((1<<RW_Switch));
	
		
		LCD_KICK();
		
		
		#endif
		
		
		#ifdef FOUR_BIT_MODE
	 
		LCD_PORTA = (LCD_PORTA & 0x0F)|(data & 0xF0);
		LCD_CTRL_PORTB |= (1<<RS_Switch);
		LCD_CTRL_PORTB &= ~((1<<RW_Switch));
	 
		LCD_KICK();
		    
		
		 LCD_PORTA = (LCD_PORTA & 0x0F)|(data << DATA_SHIFT);
		 LCD_CTRL_PORTB |= (1<<RS_Switch);
		 LCD_CTRL_PORTB &= ~((1<<RW_Switch));
		 
		 LCD_KICK();
	 
		#endif
		
	
	
	
	
}
	
//*************************STRING FUNCTION*************************************	
	
	
	
void Write_String(char* data){
	
	int count  = 0;
	
	while(*data > 0){
		
		
		Write_char(*data++);
		
		count++;
		
		if(count == 16){
			
			LCD_GOTO_XY(2,0);
			
			
		}
		
		else if(count == 32){
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
		
	
		
	}
 
	
	} 

//****************************BUSY FUNCTION**********************************

void LCD_Busy(void)
{	
	
	#ifdef  Eight_Bit_MODE

	LCD_PORTA_dir = 0x00; // port A now is input (READ FROM LCD)

	#endif
	
	
		 #ifdef FOUR_Bit_MODE
		LCD_PORTA_dir &= ~(0xFF<<DATA_SHIFT); 
		 #endif
	
	LCD_CTRL_PORTB |= (1<<RW_Switch);//Read mode
	LCD_CTRL_PORTB &= ~(1<<RS_Switch);//Register set is off
	
	LCD_KICK();
	
	LCD_PORTA_dir = 0xFF; //port A now is output (WRITE FROM LCD)
	LCD_CTRL_PORTB &= ~(1<<RW_Switch); //WRITE MODE
	 
	 

	 
}

//*****************************POSITION FUNCTION*********************************

void LCD_GOTO_XY(int line , int position){
	
	if(line == 1){
		
		if(position < 16 &&  position >=0){
			
			Write_Command(Beginning_first_line + position);
			
		}
		
		
		
	}
	
	
	else if(line == 2){
		
		if(position < 32  && position >=0)
		
		Write_Command(Beginning_second_line + position);
		
		
	}
	
	
	
	
}

void LCD_command_4bit(unsigned char command){
	
	
	LCD_Busy();
	LCD_PORTA &= 0x0F;
	LCD_PORTA |= (0xF0 & command);
	LCD_CTRL_PORTB &= ~((1<<RW_Switch)|(1<<RW_Switch));
	LCD_KICK();
	LCD_PORTA &= 0x0F;
	LCD_PORTA |= ((command << DATA_SHIFT) & 0xF0);
	LCD_KICK();
	
	
	
}