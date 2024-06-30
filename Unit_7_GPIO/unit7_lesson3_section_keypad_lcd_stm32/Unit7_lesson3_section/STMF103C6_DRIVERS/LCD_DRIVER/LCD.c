/*
 * LCD.c
 *
 
 * Created: 2/6/2024 7:09:02 AM
 *  Author: hassan
 */ 


#include "LCD.h"
#include "stdint.h"


GPIO_PinConfig_t pinCfg;

//***************************Delay Function***********************************

void wait_ms(uint32_t time){


	uint32_t i,j;
	for(i=0 ;i<time;i++){

		for(j=0;j<255;j++);

	}

}



//***************************KICK FUNCTION***********************************
void LCD_KICK(void){
	
	//this function made to disable/enable the read / write mode when we write the intended command in order to avoid any other interrupt command 
		
	
	
/*	LCD_CTRL_PORTB &= ~(1<<Enable_Switch);*/
	MCAL_GPIO_WritePin(LCD_CTRL_PORTB, Enable_Switch, GPIO_PIN_RESET);
	
	wait_ms(50);
/*
	LCD_CTRL_PORTB |= (1<<Enable_Switch);*/
	MCAL_GPIO_WritePin(LCD_CTRL_PORTB, Enable_Switch, GPIO_PIN_SET);
	
	
	
}

//***************************LCD INIT FUNCTION***********************************

void LCD_GPIO_init(void)
{
	/*	LCD_CTRL_dir |= (1<<RS_Switch) | (1<<RW_Switch) | (1<<Enable_Switch);
			LCD_CTRL_PORTB &= ~((1<<RS_Switch) | (1<<RW_Switch) | (1<<Enable_Switch));
			LCD_PORTA_dir = 0xFF;*/

			//setting control pins(B12->B14) (RS, RW, EN) to be output
			pinCfg.GPIO_PinNumber = RS_Switch;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_CTRL_PORTB, &pinCfg);


			pinCfg.GPIO_PinNumber = RW_Switch;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_CTRL_PORTB, &pinCfg);

			pinCfg.GPIO_PinNumber = Enable_Switch;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_CTRL_PORTB, &pinCfg);


			//Setting Pin 0->7 to be output with 10Mhz speed for LCD DATA D0->D7
			pinCfg.GPIO_PinNumber = LCD_D0_PIN;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);

			pinCfg.GPIO_PinNumber =	LCD_D1_PIN;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);


			pinCfg.GPIO_PinNumber = LCD_D2_PIN;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);


			pinCfg.GPIO_PinNumber = LCD_D3_PIN;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);


			pinCfg.GPIO_PinNumber = LCD_D4_PIN;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);


			pinCfg.GPIO_PinNumber = LCD_D5_PIN;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);


			pinCfg.GPIO_PinNumber = LCD_D6_PIN;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);


			pinCfg.GPIO_PinNumber = LCD_D7_PIN;
			pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
			pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);

			//RS->0 Command
			MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RS_Switch, GPIO_PIN_RESET);
			//RW->0 Write
			MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RW_Switch, GPIO_PIN_RESET);
			//EN->0
			MCAL_GPIO_WritePin(LCD_CTRL_PORTB, Enable_Switch, GPIO_PIN_RESET);

}
void LCD_Init(void)
{
	wait_ms(20);
	LCD_GPIO_init();
	wait_ms(20);
	LCD_clear_screen();
		
	#ifdef Eight_Bit_MODE

	Write_Command(eight_bit_2Line);
	
	#endif
	
/*
	#ifdef FOUR_Bit_MODE
	LCD_Busy();
	LCD_command_4bit(0x02);
	LCD_command_4bit(four_bit_2line);

	#endif
	*/
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
	
	LCD_Busy();


	 #ifdef Eight_Bit_MODE

	//LCD_PORTA = command; // look at LCD Command Macros & LCD Instruction Set Macros in the header file

	//LCD_CTRL_PORTB &= ~((1<<RS_Switch) | (1<<RW_Switch));

	//RS == 0 (command mode)
	MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RS_Switch, GPIO_PIN_RESET);
	//RW == 0 (Write mode)
	MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RW_Switch, GPIO_PIN_RESET);

 	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D0_PIN, checkbit(command,0)  );
	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D1_PIN, checkbit(command,1)  );
	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D2_PIN, checkbit(command,2)  );
	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D3_PIN, checkbit(command,3)  );
	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D4_PIN, checkbit(command,4)  );
	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D5_PIN, checkbit(command,5)  );
	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D6_PIN, checkbit(command,6)  );
	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D7_PIN, checkbit(command,7)  );

	wait_ms(30);
	LCD_KICK();
	#endif
	
	
/*	 #ifdef FOUR_BIT_MODE
	 LCD_Busy();
	 LCD_PORTA = (LCD_PORTA & 0x0F)|(command & 0xF0);
	 LCD_CTRL_PORTB &= ~((1<<RS_Switch) | (1<<RW_Switch)); 
 
	 LCD_KICK();
	  
	  LCD_PORTA = (LCD_PORTA & 0x0F)|(command << DATA_SHIFT);
	  LCD_CTRL_PORTB &= ~((1<<RS_Switch) | (1<<RW_Switch));
	 
	  LCD_KICK();
	   
	 
	 #endif
		
	*/
}

//******************************CHARACTER FUNCTION********************************


void Write_char(unsigned char data){
	
		#ifdef Eight_Bit_MODE
		LCD_Busy();
/*
//		LCD_CTRL_PORTB |= (1<<RS_Switch);
//		LCD_PORTA = data; // look at LCD Command Macros & LCD Instruction Set Macros in the header file
//		LCD_CTRL_PORTB |= (1<<RS_Switch);
//		LCD_CTRL_PORTB &= ~((1<<RW_Switch));
*/

		MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RS_Switch, GPIO_PIN_SET);

	 	MCAL_GPIO_WritePin(LCD_PORTA, LCD_D0_PIN, checkbit(data,0)  );
		MCAL_GPIO_WritePin(LCD_PORTA, LCD_D1_PIN, checkbit(data,1)  );
		MCAL_GPIO_WritePin(LCD_PORTA, LCD_D2_PIN, checkbit(data,2)  );
		MCAL_GPIO_WritePin(LCD_PORTA, LCD_D3_PIN, checkbit(data,3)  );
		MCAL_GPIO_WritePin(LCD_PORTA, LCD_D4_PIN, checkbit(data,4)  );
		MCAL_GPIO_WritePin(LCD_PORTA, LCD_D5_PIN, checkbit(data,5)  );
		MCAL_GPIO_WritePin(LCD_PORTA, LCD_D6_PIN, checkbit(data,6)  );
		MCAL_GPIO_WritePin(LCD_PORTA, LCD_D7_PIN, checkbit(data,7)  );

		MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RW_Switch, GPIO_PIN_RESET);


		LCD_KICK();

		MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RS_Switch, GPIO_PIN_RESET);
		
		#endif
		
/*
		
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
*/
		
	
	
	
	
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



	pinCfg.GPIO_PinNumber = GPIO_PINS_7;
	pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
	MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);



	//LCD_PORTA_dir = 0x00; // port A now is input (READ FROM LCD)

	#endif
	
/*

		 #ifdef FOUR_Bit_MODE
		LCD_PORTA_dir &= ~(0xFF<<DATA_SHIFT);
		 #endif
*/



	//LCD_CTRL_PORTB |= (1<<RW_Switch);//Read mode
	//LCD_CTRL_PORTB &= ~(1<<RS_Switch);//Register set is off

		//RW == 1 (READ MODE)
		MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RW_Switch, GPIO_PIN_SET);
		//RS == 0 (Command Mode)
		MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RS_Switch, GPIO_PIN_RESET);

		while(MCAL_GPIO_ReadPin(LCD_PORTA, LCD_D7_PIN) & 1);//checking on pin D7 if it's busy or not

		LCD_KICK();

	
	//LCD_PORTA_dir = 0xFF; //port A now is output (WRITE FROM LCD)
	//LCD_CTRL_PORTB &= ~(1<<RW_Switch); //WRITE MODE
	 

	//set D7 to to be output
	pinCfg.GPIO_PinNumber = LCD_D7_PIN;
	pinCfg.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	pinCfg.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(LCD_PORTA, &pinCfg);

	//RW == 0 (Write Mode)
	MCAL_GPIO_WritePin(LCD_CTRL_PORTB, RW_Switch, GPIO_PIN_RESET);

	 
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
	
	
	/*LCD_Busy();
	LCD_PORTA &= 0x0F;
	LCD_PORTA |= (0xF0 & command);
	LCD_CTRL_PORTB &= ~((1<<RW_Switch)|(1<<RW_Switch));
	LCD_KICK();
	LCD_PORTA &= 0x0F;
	LCD_PORTA |= ((command << DATA_SHIFT) & 0xF0);
	LCD_KICK();
	*/
	
	
}
