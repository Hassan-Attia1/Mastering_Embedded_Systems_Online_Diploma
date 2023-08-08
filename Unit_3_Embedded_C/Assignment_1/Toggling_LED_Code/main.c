
 /******************************************************************************
 * @file           : main.c
 * @author         : Hassan Attia
 * @brief          : Toggling LED
 *******************************************************************************/


#include <stdint.h>

#define RCC_BASE             0x40021000
#define GPIO_PORT_A_BASE     0x40010800

#define APB2ENR              *(volatile uint32_t*) (RCC_BASE + 0x18)
#define PORT_A_CRH           *(volatile uint32_t*) (GPIO_PORT_A_BASE + 0x04)
#define PORT_A_ODR           *(volatile uint32_t*) (GPIO_PORT_A_BASE + 0x0c)

int main(void)
{

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
