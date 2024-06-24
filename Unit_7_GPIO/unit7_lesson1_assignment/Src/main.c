//Hassan Attia



//RCC Registers
#define RCC_Base      0x40021000
#define RCC_APB2ENR   *(volatile unsigned int*)(RCC_Base + 0x18)


//GPIO_A Registers
#define GPIO_PORT_A   0x40010800
#define GPIOA_CRL	  *(volatile unsigned int*)(GPIO_PORT_A + 0x0)
#define GPIOA_CRH     *(volatile unsigned int*)(GPIO_PORT_A + 0x04)
#define GPIOA_ODR     *(volatile unsigned int*)(GPIO_PORT_A + 0x0C)
#define GPIOA_IDR	  *(volatile unsigned int*)(GPIO_PORT_A + 0x08)

//GPIO_B Registers

#define GPIO_PORT_B		0x40010C00
#define GPIOB_CRL	*(volatile unsigned int*)(GPIO_PORT_B + 0x0)
#define GPIOB_CRH	*(volatile unsigned int*)(GPIO_PORT_B + 0x4)
#define GPIOB_ODR	*(volatile unsigned int*)(GPIO_PORT_B + 0x0C)
#define GPIOB_IDR	*(volatile unsigned int*)(GPIO_PORT_B + 0x08)

//init function for each peripheral

void GPIO_init(void){
	GPIOA_CRL =0x0;
	GPIOB_CRL =0x0;

	//setting pin A1 to act as floating input pin

	GPIOA_CRL |= (0b01<<6);

	 //setting pin B1 to act as output(PULL) pin
	GPIOB_CRL &= ~(0b11<<6);
	GPIOB_CRL |= (0b01<<4);

	//setting pin A13 to act as floating input pin
	GPIOA_CRH &= ~(0b11<<20);
	GPIOA_CRH |= (0b01<<22);

	//setting pin B13 to act as output(PULL) pin
	GPIOB_CRH &= ~(0b11<<22);
	GPIOB_CRH |= (0b01<<20);

}


void wait(int x){

	unsigned int i , j;

	for(i = 0 ; i<x ; i++){

		for(j = 0 ; j<255 ; j++);
	}
}





void clock_init(void){


	//enabling clock for GPIO port A
		RCC_APB2ENR |= (1 << 2);
		//enabling clock for GPIO port B
		RCC_APB2ENR |= (1 << 3);



}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1){

		if( ( ( GPIOA_IDR & (1<<1) ) >> 1 )  == 0 ){

			//Toggling on LED 1  at pinB1 (single press)
			GPIOB_ODR ^= 1 << 1;

			while(  ( (GPIOA_IDR & (1<<1)  ) >> 1 ) == 0 );

		}



		if(  ( (GPIOA_IDR & (1<<13) ) >>13)  == 1 ){

			//Toggling on LED 2 at pinB13 (MUltiple press)
			GPIOB_ODR ^= 1 << 13;



		}

		wait(10);

	}



}


