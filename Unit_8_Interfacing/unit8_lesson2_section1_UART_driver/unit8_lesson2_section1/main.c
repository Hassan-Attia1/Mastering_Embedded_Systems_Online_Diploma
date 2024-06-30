/*
 * unit8_lesson2_section1.c
 *
 * Created: 4/3/2024 5:25:34 AM
 * Author : hassa
 */ 

//#include <avr/io.h>
#include "MCAL/atmega_device_header/atmega32.h"
#include "LCD/LCD.h"
#include "MCAL/USART.h"
	

//char name[] = "hassan";

int main(void)
{	// unsigned char x;
 	LCD_Init();
 
	
	//USART Init
	USART_PinCfg UART_Pincfg ;
	UART_Pincfg.Data_Size = eight_bits;
	UART_Pincfg.Mode_of_Operation = Asynchronous;
	UART_Pincfg.Parity = Parity_Disable;
	UART_Pincfg.Stop_bits = Stop_1bit;
	UART_Pincfg.Baudrate = Baud_9600_N;  
	UART_Pincfg.Baudrate = TX_RX_Transmit_AND_Receive;
	USART_init( &UART_Pincfg);
	 
	//Send message
 
  
	USART_SEND_String((uint8_t*)"HI,Iam hassan");
	 
 
	
   
    while (1){
		
		  
		
	} 
				
	
	
	
	
	
	
	
}

