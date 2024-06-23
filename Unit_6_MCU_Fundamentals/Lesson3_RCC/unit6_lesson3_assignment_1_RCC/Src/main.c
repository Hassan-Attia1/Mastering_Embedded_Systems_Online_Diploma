  /******************************************************************************
 * @file           : main.c
 * @author         : Hassan Attia
 * @brief          : Toggling LED
 *******************************************************************************/


#include <stdint.h>

#define RCC_BASE             0x40021000
#define GPIO_PORT_A_BASE     0x40010800

#define RCC_CFGR			 *(volatile uint32_t*)(RCC_BASE + 0x04)
#define APB2ENR              *(volatile uint32_t*) (RCC_BASE + 0x18)
#define PORT_A_CRH           *(volatile uint32_t*) (GPIO_PORT_A_BASE + 0x04)
#define PORT_A_ODR           *(volatile uint32_t*) (GPIO_PORT_A_BASE + 0x0c)


void clock_init(){

	//setting APB1 to run on 4MHZ
	RCC_CFGR |= (0b100 << 8);
	//setting APB2 to run on 2MHZ
	RCC_CFGR |= (0b101 << 11);



}

int main(void)
{


	clock_init();

	int i = 0;

  APB2ENR |= 1<<2;

  PORT_A_CRH &= 0xff0fffff;
  PORT_A_CRH |= 0x00200000;


  while(1){



		  PORT_A_ODR |= 1<<13;
		  for(  i = 0 ; i<2000 ; i++);
		  PORT_A_ODR &= ~(1<<13);
		  for(  i = 0 ; i<2000 ; i++);


  }



	return 0;
}
