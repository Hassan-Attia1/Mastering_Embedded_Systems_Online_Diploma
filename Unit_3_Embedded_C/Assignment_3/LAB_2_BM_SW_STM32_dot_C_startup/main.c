//Hassan Attia

typedef volatile unsigned int vuint32_t;


#define RCC_Base      0x40021000
#define GPIO_PORT_A   0x40010800
#define RCC_APP2ENR   *(vuint32_t*)(RCC_Base + 0x18)
#define GPIOA_CRH     *(vuint32_t*)(GPIO_PORT_A + 0x04)
#define GPIOA_ODR     *(vuint32_t*)(GPIO_PORT_A + 0x0C)

typedef union {

	vuint32_t all_fileds;
	struct{

		vuint32_t reserved:13;
		vuint32_t pin_13:1;


	}Pins;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIO_PORT_A + 0x0c);
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables [3] = {1,2,3};
unsigned int bss_global_var = 0;
int i;
int main(void)
{
	int i;
	RCC_APP2ENR |= 1<<2;
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;

	while(1){

		R_ODR->Pins.pin_13=1;
		for( i = 0; i<5000; i++);
		R_ODR->Pins.pin_13=0;
		for( i = 0 ; i<5000; i++);



	}

 

}
