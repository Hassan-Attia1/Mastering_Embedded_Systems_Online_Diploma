





/*
 *
 *
 *Author:Hassan Attia
 *SPI LAB 1
 *
 *
 *************************************************************************************************
 *  Terminal 1 <---> USART 1 : MCU1 : (SPI1 Master)--> (SPI2 Slave) : MCU2: USART2 --> Terminal2
 *************************************************************************************************
 *
 * */








#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif




//#define MCU_Act_as_a_slave
 #define MCU_Act_as_a_master





#include "Device_header/stm32f103x6.h"
#include "EXTI/stm32_F103C6_EXTI_driver.h"
#include "GPIO/stm32_F103C6_gpio_driver.h"
#include "USART/uart.h"
#include "SPI/SPI.h"
void init_clk(void){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();




}




unsigned char ch;
void hassan_callback(void){

#ifdef MCU_Act_as_a_master
	MCAL_UART_ReceiveData(USART1,  &ch, Disable);
	MCAL_UART_SendData(USART1,  &ch, Enable);
	//Sending data to spi
	MCAL_GPIO_WritePin(GPIOA, GPIO_PINS_4, GPIO_PIN_RESET);
	MCAL_SPI_TX_RX(SPI1, &ch, Polling_Enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PINS_4, GPIO_PIN_SET);
#endif
}



	void Hassan_SPI1_IRQ_Callback (struct S_IRQ_SRC irq_src){

#ifdef MCU_Act_as_a_slave

		if(irq_src.RXNE){
			ch = 0xf;
			MCAL_SPI_TX_RX(SPI1, &ch, Polling_Disable);
			MCAL_UART_SendData(USART1, &ch, Enable);

		}
#endif

	}










int main(void)
{

	init_clk();
	//UART INIT Configuration
	USART_Config uartCFG;
	uartCFG.Baud_Rate = USART_BAUDRATE_115200;
	uartCFG.Flow_Control = USART_FLOW_CONTROL_None;
	uartCFG.IRQ_Enable = USART_IRQ_Enable_RXNEIE;
	uartCFG.Parity = USART_Parity_Type_None;
	uartCFG.Stop_bits = USART_STOP_Bits_one;
	uartCFG.Payload_Length = USART_8_DATA_Bits;
	uartCFG.USART_Mode = USART_MODE_TX_RX;
	uartCFG.P_IRQ_Callback = hassan_callback ;
	MCAL_UART_Init(USART1, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);
	//SPI1 INIT Configuration
	//PA.4 : SPI1_NSS
	//PA.5 : SPI1_SCK
	//PA.6 : SPI1_MISO
	//PA.7 : SPI1_MOSI
	SPI_Config SPI_CFG;
	//Common Configuration
	SPI_CFG.CLK_Phase = SPI_CLK_Phase_Second_Edge_Capture;
	SPI_CFG.CLK_Polarity = SPI_CLK_Polarity_One_Idle;
	SPI_CFG.Communitcation_Mode = SPI_Direction_2Lines;
	SPI_CFG.Data_Size = SPI_DATASize_8BIT;
	SPI_CFG.Frame_Format = SPI_Frame_Format_MSB_transmitted_first;
	//We use HSI 8MHz CLK from APB2
	SPI_CFG.SPI_Baud_Rate_Scaler = SPI_BaudRate_Prescaler_Divided_by_8;
#ifdef MCU_Act_as_a_master
	SPI_CFG.Device_Mode = SPI_Device_Mode_Master;
	SPI_CFG.IRQ_Enable = SPI_IRQ_Enable_None;
	SPI_CFG.P_IRQ_CallBack = NULL;
	SPI_CFG.NSS = SPI_NSS_SW_SSI_Set;
	GPIO_PinConfig_t GPIO_NSS_PIN;
	//	control NSS by using GPIO PA.4


	GPIO_NSS_PIN.GPIO_PinNumber = GPIO_PINS_4;
	GPIO_NSS_PIN.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	GPIO_NSS_PIN.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(GPIOA, &GPIO_NSS_PIN);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PINS_4, GPIO_PIN_SET);
#endif

#ifdef MCU_Act_as_a_slave
	SPI_CFG.Device_Mode = SPI_Device_Mode_SLAVE;
	SPI_CFG.IRQ_Enable = SPI_IRQ_Enable_RXNEIE;
	SPI_CFG.NSS = SPI_NSS_HW_Slave;
	SPI_CFG.P_IRQ_CallBack = Hassan_SPI1_IRQ_Callback;
#endif
	MCAL_SPI_Init(SPI1, &SPI_CFG);
	MCAL_SPI_GPIO_Set_Pins(SPI1);



	/* Loop forever */
	while(1){


	}







}
