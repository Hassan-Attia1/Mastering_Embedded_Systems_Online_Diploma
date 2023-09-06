#include "uart.h"

unsigned char string_buffer [100] = "Learn-in-Depth:Hassan Attia";
const unsigned char string_buffer2 [100] = "ro data"; //To display rodata section


void main (void){

 Uart_send_string (string_buffer);

}