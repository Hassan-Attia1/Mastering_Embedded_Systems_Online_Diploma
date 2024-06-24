/*
 * unit7_section1_task1.c
 *
 * Created: 1/30/2024 2:24:46 PM
 * Author : hassan
 */ 

#define F_CPU 8000000UL
#include <util/delay.h> 
#include "bit_manipulation.h"
 

#define PORTD	*(volatile unsigned char *)(0x32)
#define DDRD	*(volatile unsigned char *)(0x31)
#define PIND	*(volatile unsigned char *)(0x30)


//init functions
void gpio_init(void){
	
	//setting pin D0 as input pull_down
	ResetBit(DDRD,0);
	ResetBit(PORTD,0);
	//setting pins D5,D6,D7 as output (High)
	SetBit(DDRD,5);
	SetBit(DDRD,6);
	SetBit(DDRD,7);
	
}

void my_delay(unsigned int x){
	
	unsigned int i,j;
	
	for(i = 0  ; i<x ; i++){
		
		for(j=0 ; j < 256 ; j++);
		
	}
	
	
}



int main(void)
{	
	gpio_init();
    unsigned int counter = 0;
    while (1) 
    {
		if(ReadBit(PIND,0) == 1){
			
			
			for( counter = 5 ;counter<=7 ; counter ++){
				
				ToggleBit(PORTD,counter);
				_delay_ms(2000);
				
			}
 
			while(ReadBit(PIND,0) == 1){}
			
			
		}
		
		
		
		
		
    }
}

