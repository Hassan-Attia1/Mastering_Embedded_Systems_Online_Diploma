//Hassan Attia


//RCC Registers
#define RCC_Base      0x40021000
#define RCC_APB2ENR   *(volatile unsigned int*)(RCC_Base + 0x18)


//GPIO_A Registers
#define GPIO_PORT_A   0x40010800
#define GPIOA_CRH     *(volatile unsigned int*)(GPIO_PORT_A + 0x04)
#define GPIOA_ODR     *(volatile unsigned int*)(GPIO_PORT_A + 0x0C)

//EXTI Registers
#define EXTI_Base	0x40010400
#define EXTI_IMR	*(volatile unsigned int*)(EXTI_Base + 0x00)
#define EXTI_RTSR	*(volatile unsigned int*)(EXTI_Base + 0x08)
#define EXTI_PR		*(volatile unsigned int*)(EXTI_Base + 0x14)

//AFIO Registers
#define AFIO_Base 	0x40010000
#define AFIO_EXTICR1 *(volatile unsigned int*)(AFIO_Base + 0x08)

//Cortex M3 NVIC Register

#define NVIC_ISER *(volatile unsigned int*)(0xE000E100)

//init function for each peripheral
void GPIO_init(void);
void EXTI0_init(void);
void AFIO_init(void);

//IRQs
void EXTI0_IRQHandler (void);


int main(void)
{
	GPIO_init();
	AFIO_init();
	EXTI0_init();

	while(1);





	return 0;

}


void GPIO_init(void){
	//enabling clock for GPIO port A
	RCC_APB2ENR |= (1 << 2);
	//make port A pins(from 0 to 7) acting as a  Floating input
	GPIOA_CRH |= (0b01 << 2);
	//make port A pins(from 8 to 15) acting as an output
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;


}


void EXTI0_init(void){


	//configure port A0 as an input to EXTI_0
	AFIO_EXTICR1 = (0b0000 << 0 );
	//Trigger a rising signal for EXTI_0
	EXTI_RTSR |= (1 << 0 );
	//Mask EXTI_0
	EXTI_IMR |= ( 1 << 0 );
	//Enabling EXI_0 to be sensible by NVIC
	//check IVT index number (6)
	NVIC_ISER |= (1 << 6);

}

void AFIO_init(void){
	//enabling AFIO clock for use of EXTI

	RCC_APB2ENR |= (1 << 0);



}


void EXTI0_IRQHandler (void){

	//enabling pinA.13
	GPIOA_ODR ^= (1<<13);


	//Clearing Line 0 pending register to avoid interrupt overhead
	EXTI_PR |= ( 1 << 0 );

}

