#include "uart.h"

unsigned char string_buffer1 [100] = "Learn-in-Depth: Hassan Attia";
const unsigned char string_buffer2 [100] =  "Learn-in-Depth: Hassan Attia";



void main (void){
	

uart_send_string (string_buffer1);


}