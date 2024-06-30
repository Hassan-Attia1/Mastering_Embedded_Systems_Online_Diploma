//Hassan Attia



#include "LCD_DRIVER/LCD.h"
#include "Device_header/stm32f103x6.h"
#include "EXTI/stm32_F103C6_EXTI_driver.h"
#include "GPIO/stm32_F103C6_gpio_driver.h"

 unsigned char EXTI_flag ;
 EXTI_PinConfig_t PINCONFIG;
void mywait(unsigned int time)
{
	int i, j;

	for(i = 0 ; i < 255 ; i++){

		for(j = 0 ; j < time ; j ++);

	}



}

void EXTII9_callback(void)
{


	// EXTI_flag = 1;
	Write_String("IRQ EXTI9 happened _|-");
	mywait(400);
    LCD_clear_screen();


}

void RCC_clock_init(void){

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();


}




int main(void)
{

//RCC init
RCC_clock_init();

//ECU Init
LCD_Init();
mywait(200);


//set an interrupt

PINCONFIG.EXTI_PIN =  EXTI9PB9;
PINCONFIG.Trigger_type = EXTI_Trigger_Rising;
PINCONFIG.PTF_IRQ_Callback = EXTII9_callback;
PINCONFIG.IRQ_EN = EXTI_IRQ_Enable;
MCAL_EXTI_GPIO_Init(&PINCONFIG);

Write_String("hello");
mywait(200);
LCD_clear_screen();

//Code
EXTI_flag = 1;
while(1){

/*
if(EXTI_flag){

	LCD_clear_screen();
	EXTI_flag = 0;

}
*/


}



	return 0;
}
