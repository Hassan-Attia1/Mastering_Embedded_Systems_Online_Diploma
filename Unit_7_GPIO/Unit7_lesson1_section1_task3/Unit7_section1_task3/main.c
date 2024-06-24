/*
 * Unit7_section1_task3.c
 *
 * Created: 1/31/2024 2:30:38 PM
 * Author : hassan
 */ 

 

#define F_CPU 8000000UL
#include <util/delay.h>


#define PORTD	*(volatile unsigned char *)(0x32)
#define DDRD	*(volatile unsigned char *)(0x31)
#define PIND	*(volatile unsigned char *)(0x30)

#define SetBit(reg,bit)	(reg|= (1<<bit))
#define ResetBit(reg,bit)	(reg &= ~(1<<bit))
#define ToggleBit(reg,bit)	(reg ^= (1<<bit))
#define ReadBit(reg,bit)	((reg>>bit) & 1)


void gpio_init(void){
	
	//setting D0 to be input floating
	ResetBit(DDRD,0);
	ResetBit(PORTD,0);
	//Setting D4 to be output (sink)
	SetBit(DDRD,4);
	
	
}

int main(void)
{
	gpio_init();
	
	
    /* Replace with your application code */
    while (1) 
    {
		if(ReadBit(PIND,0) == 1){
			
			//toggling D4 to turn on the buzzer
			ToggleBit(PORTD,4);
			
			while(ReadBit(PIND,0) == 1){}
			
			
		}
		
    }
}

