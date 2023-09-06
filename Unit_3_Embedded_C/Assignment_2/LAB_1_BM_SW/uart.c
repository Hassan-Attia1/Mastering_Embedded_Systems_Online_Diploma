#include "uart.h"

//UART PORT 0 DATA REGISTER
#define UART0_DR       *((volatile unsigned int* const)((unsigned int*)0x101f1000))


// Function Definition
void Uart_send_string (unsigned char *p_tx_string){

while(*p_tx_string != '\0'){

UART0_DR =(unsigned int) (*p_tx_string);  //transmit the string charcter by character
p_tx_string++;   //reading the next character
}




}