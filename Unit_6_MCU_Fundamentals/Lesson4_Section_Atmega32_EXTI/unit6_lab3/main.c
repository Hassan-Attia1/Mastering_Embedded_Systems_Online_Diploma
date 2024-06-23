/*
 * unit6_lab3.c
 *
 * Created: 1/22/2024 9:42:14 PM
 * Author : hassan attia
 */ 



#define F_CPU 1000000UL 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> 
 
 

//init functions prototypes
void external_intrrupt_init(void);
void GPIO_init(void);



	
	ISR(INT0_vect){
		
		//LED is on PORTD5
		PORTD ^= 1 << 5;
		
		_delay_ms(2000);
		//LED is off
		PORTD ^= 1 << 5;
		
		//Turning off the interrupt flag
		GIFR |= 1 << 6;
		
	}
	
	ISR(INT1_vect){
		
		
		//LED is on PORTD6
		PORTD ^= 1 << 6;
		
		_delay_ms(2000);
		
		//LED is off
		PORTD ^= 1 << 6;
		
		//Turning off the interrupt flag
		GIFR |= 1 << 7;
	}
	
	ISR(INT2_vect){
		
		//LED is on PORTD7
		PORTD ^= 1 << 7;
		
		_delay_ms(2000);

		PORTD ^= 1 << 7;
		//Turning off the interrupt flag
		GIFR |= 1 << 5;
	}
	
	

int main(void)
{	
	GPIO_init();
	external_intrrupt_init();
	
	
 
    while (1) {}
	
	return 0;
}


void external_intrrupt_init(void){


//disabling External interrupts
SREG &= ~(1<<7);


//enabling interrupts 0,1,2
GICR &= ~(1<<7);
GICR |= (1<<7);  //INT1 is enabled

GICR &= ~(1<<6);
GICR |= (1<<6); //INT0 is enabled

GICR &= ~(1<<5);
GICR |= (1<<5); //INT2 is enabled

 
//setting the sense control for each interrupt
MCUCR &= ~(0b00<<0);
MCUCR |= 0b01 << 0; //INT0 set to rising and falling edges

MCUCR &= ~(0b00<<2);
MCUCR |= 0b11 << 2; //INT1 set to rising edge

MCUCSR &= ~(1<<6);
MCUCSR |= 0 << 6;	//INT2 set to rising edge


//enabling External interrupts
SREG |= 1<<7;



}




void GPIO_init(void){
	
//INPUTS


//PORT B2
DDRB &= ~(1<<2);
DDRB |= 0 << 2;

//PORTS D2 , D3
DDRD &= ~(1<<2);
DDRD |= 0 << 2;

DDRD &= ~(1<<3);
DDRD |= 0 << 3;




//OUTPUTS

//PORTS D5, D6, D7
DDRD &= ~(1<<5);
DDRD |= 1 << 5;

DDRD &= ~(1<<6);
DDRD |= 1 << 6;
PORTD &= ~(1<<6);

DDRD &= ~(1<<7);
DDRD |= 1 << 7;
PORTD &= ~(1<<7);
	
}


 
