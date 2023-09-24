#include "uart.h" // including function prototype
#define UART0DR *((volatile unsigned int* const)((unsigned int*) 0x101f1000)) // uart data register base adress and port 0 adress

void uart_send_string(unsigned char* p_tx_string){
	
	while(*p_tx_string != 0){
		
		UART0DR = (unsigned int)*p_tx_string; //printing character 
		p_tx_string++; // pointing to the next character
		
		
		
	}


}