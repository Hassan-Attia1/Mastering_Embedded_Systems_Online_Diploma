//Hassan_Attia
 #include<stdint.h>

#define SYSCTL_RCGC2_R    (*((volatile unsigned long*)0x400FE108))// GPIO PORT F ENABLE 
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))// WRINTG DATA ON PORT F PIN 3
#define	GPIO_PORTF_DIR_R  (*((volatile unsigned long*)0x40025400)) // PORT F PIN 3 DIRECTION
#define GPIO_PORTF_DEN_R  (*((volatile unsigned long*)0x4002551C)) // PORT F PIN 3 ENABLE



 


int main(){
 volatile unsigned long delay_count;
 SYSCTL_RCGC2_R = 0x00000020;
 //delay to ensure GPIO is turned on and running
for(delay_count = 0; delay_count<200; delay_count++);
GPIO_PORTF_DIR_R |= 1<<3; // set pin 3 to be output
GPIO_PORTF_DEN_R |= 1<<3;// enabling pin 3
 
while(1){
	//LED turn on
	GPIO_PORTF_DATA_R |= 1<<3;
	
	for(delay_count = 0; delay_count<200000; delay_count++);
	
	//LED turn off
	GPIO_PORTF_DATA_R &= ~(1<<3);
	
	for(delay_count = 0; delay_count<200000; delay_count++);
	
	}


return 0;
}