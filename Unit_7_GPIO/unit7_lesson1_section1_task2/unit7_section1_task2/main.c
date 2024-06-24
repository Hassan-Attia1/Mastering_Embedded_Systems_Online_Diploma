/*
 * unit7_section1_task2.c
 *
 * Created: 1/31/2024 12:23:22 AM
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
	
//setting D0 to be input pull-down
	ResetBit(DDRD,0);
	ResetBit(PORTD,0);
	
//setting D5,D6,D7 to be output(source or push)
	SetBit(DDRD,5);
	SetBit(DDRD,6);
	SetBit(DDRD,7);
 
}




 

 


int main(void)
{	
	gpio_init();
     int counter = 0;
	
	
    while (1) 
    {	
		if(ReadBit(PIND,0) == 1){
			
			
			if(counter == 0 )
			ToggleBit(PORTD,5);
			else if(counter == 1)
			ToggleBit(PORTD,6);
			else
			ToggleBit(PORTD,7);
			
			
			while(ReadBit(PIND,0) == 1){}
			
				counter ++;
				if(counter>2)
				counter =0;
			
		}
		
	
		
    }
}

