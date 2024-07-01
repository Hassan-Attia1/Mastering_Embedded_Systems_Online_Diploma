/*
 * SPI.c
 *
 *  Created on: Apr 20, 2024
 *      Author: hassa
 */


#include "SPI/SPI.h"







//=====================================================
//		                 Generic Variables
//=====================================================


SPI_Config* GP_SPI_config  [2] = {NULL,NULL};



//=====================================================
//		                  Generic Macros
//=====================================================


#define SPI1_Index	0
#define SPI2_Index  1
#define SPI_SR_RXNE	1
#define SPI_SR_TXE	2
//=====================================================
//		                  Generic Functions
//=====================================================



//=====================================================
//		                  APIs
//=====================================================






/*=======================================================================================================
 *
 * @Fn    			-MCAL_SPI_Init
 * @brief			-Initializes SPI (note:this only supports Full-Duplex mode only)
 * @Param[in]		-SPIx: where x can be (1..3 depending on which SPI will be used )
 * @Param[in]		-SPI_Config: pointer to a  SPI_Config structure that contains the
 * 					   the configuration info for the specified SPI PIN.
 * @retval			-None
 * @Note			-Support Full Duplex Master/Slave only & NSS HW/SW for master and slave and HSI 8MHz Clock speed only
 *					-In case off master you have to configure pin and drive it
 * */





void MCAL_SPI_Init (SPI_typedef* SPIx, SPI_Config* SPI_Config)
{

	//Safety configuration register
	uint16_t TempReg_CR1 = 0;
	uint16_t TempReg_CR2 = 0;


	if (SPIx == SPI1){

		GP_SPI_config[SPI1_Index] = SPI_Config;
		RCC_SPI1_CLK_EN();

	}
	else if (SPIx == SPI2){
		GP_SPI_config[SPI2_Index] = SPI_Config;
		RCC_SPI2_CLK_EN();

	}


	//Enable Bit 6 SPE: SPI enable
	TempReg_CR1 |= (0x1UL<<6);
	//Master or Slave ->Bit 2 MSTR: Master selection
	TempReg_CR1 |= SPI_Config->Device_Mode;
	//SPI_Communitcation
	TempReg_CR1 |= SPI_Config->Communitcation_Mode;
	//SPI Data Format
	TempReg_CR1 |= SPI_Config->Data_Size;
	//SPI Frame Format
	TempReg_CR1 |= SPI_Config->Frame_Format;
	//SPI Clock Polarity
	TempReg_CR1 |= SPI_Config->CLK_Polarity;
	//SPI Clock Phase
	TempReg_CR1 |= SPI_Config->CLK_Phase;
	//SPI Baudrate
	TempReg_CR1 |= SPI_Config->SPI_Baud_Rate_Scaler;
	//Slave Select (NSS)
	if(SPI_Config->NSS == SPI_NSS_HW_Master_Output_Enable	 ){
		TempReg_CR2 |= SPI_Config->NSS;
	}
	else if(SPI_Config->NSS == SPI_NSS_HW_Master_Output_disable){
		TempReg_CR2 &= SPI_Config->NSS;

	}
	else
	{
		TempReg_CR1 |= SPI_Config->NSS;

	}
	//IRQ
	if(SPI_Config->IRQ_Enable != SPI_IRQ_Enable_None)
	{
		TempReg_CR2 |= SPI_Config->IRQ_Enable;

		if(SPIx == SPI1){
			NVIC_IRQ35_SPI1_Enable;


		}
		else if(SPIx == SPI2){
			NVIC_IRQ36_SPI2_Enable;
		}


	}

	SPIx->SPI_CR1 = TempReg_CR1;
	SPIx->SPI_CR2 = TempReg_CR2;



}









/*=======================================================================================================
 *
 * @Fn    			-MCAL_SPI_DeInit
 * @brief			-Reset SPI to its default settings
 * @Param[in]		-SPIx: where x can be (1..3 depending on which SPI will be used )
 * @retval			-None

 * */




void MCAL_SPI_DeInit (SPI_typedef* SPIx)
{


	if(SPIx == SPI1)
	{

		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_CLK_DIS();


	}
	else if(SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_CLK_DIS();


	}

}







/*=======================================================================================================
 *
 * @Fn    			-MCAL_SPI_GPIO_Set_Pins
 * @brief			-Routing GPIO Pins for SPI use
 * @Param[in]		-SPIx: where x can be (1..3 depending on which SPI will be used )
 * @Note			-Support FULL Duplex Mode and HSI 8MHz Clock speed only
 *
 * */

void MCAL_SPI_GPIO_Set_Pins(SPI_typedef* SPIx)
{
	GPIO_PinConfig_t SPI_Config;

	if(SPIx == SPI1)
	{



		if(GP_SPI_config[SPI1_Index]->Device_Mode == SPI_Device_Mode_Master)
		{
			//Setting NSS Pin(master)
			//PA.4 : SPI1_NSS
			if(GP_SPI_config[SPI1_Index]->NSS == SPI_NSS_HW_Master_Output_disable){

				SPI_Config.GPIO_PinNumber = GPIO_PINS_4;
				SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
				MCAL_GPIO_INIT(GPIOA, &SPI_Config);


			}
			else if(GP_SPI_config[SPI1_Index]->NSS == SPI_NSS_HW_Master_Output_Enable){

				SPI_Config.GPIO_PinNumber = GPIO_PINS_4;
				SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Alternate_Output_PP;
				SPI_Config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
				MCAL_GPIO_INIT(GPIOA, &SPI_Config);


			}


			//Setting SCK (master)
			//PA.5 : SPI1_SCK
			SPI_Config.GPIO_PinNumber = GPIO_PINS_5;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Alternate_Output_PP;
			SPI_Config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(GPIOA, &SPI_Config);

			//Setting MISO(Full Duplex / master)
			//PA.6 : SPI1_MISO
			SPI_Config.GPIO_PinNumber = GPIO_PINS_6;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
			MCAL_GPIO_INIT(GPIOA, &SPI_Config);

			//Setting MOSI(Full Duplex / master)
 			SPI_Config.GPIO_PinNumber = GPIO_PINS_7;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Alternate_Output_PP;
			SPI_Config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(GPIOA, &SPI_Config);





		}else
		{
			//Slave Configuration
			if(GP_SPI_config[SPI1_Index]->NSS == SPI_NSS_HW_Slave){
				//Setting NSS Pin
				//PA.4 : SPI1_NSS
				SPI_Config.GPIO_PinNumber = GPIO_PINS_4;
				SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
				MCAL_GPIO_INIT(GPIOA, &SPI_Config);
			}


			//Setting SCK (Slave)
			//PA.5 : SPI1_SCK
			SPI_Config.GPIO_PinNumber = GPIO_PINS_5;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
			MCAL_GPIO_INIT(GPIOA, &SPI_Config);

			//Setting MISO(Full Duplex / Slave(Point to Point))
			//PA.6 : SPI1_MISO
			SPI_Config.GPIO_PinNumber = GPIO_PINS_6;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Alternate_Output_PP;
			SPI_Config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(GPIOA, &SPI_Config);

			//Setting MOSI(Full Duplex / Slave)
			//PA.7 : SPI1_MOSI
			SPI_Config.GPIO_PinNumber = GPIO_PINS_7;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
			MCAL_GPIO_INIT(GPIOA, &SPI_Config);


		}




	}

	else if(SPIx == SPI2)
	{

		if(GP_SPI_config[SPI2_Index]->Device_Mode == SPI_Device_Mode_Master)
		{
			//Setting NSS Pin(master)
			//PA.12 : SPI2_NSS
			if(GP_SPI_config[SPI2_Index]->NSS == SPI_NSS_HW_Master_Output_disable){

				SPI_Config.GPIO_PinNumber = GPIO_PINS_12;
				SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
				MCAL_GPIO_INIT(GPIOB, &SPI_Config);


			}
			else if(GP_SPI_config[SPI2_Index]->NSS == SPI_NSS_HW_Master_Output_Enable){

				SPI_Config.GPIO_PinNumber = GPIO_PINS_12;
				SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Alternate_Output_PP;
				SPI_Config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
				MCAL_GPIO_INIT(GPIOB, &SPI_Config);


			}


			//Setting SCK (master)
			//PA.13 : SPI2_SCK
			SPI_Config.GPIO_PinNumber = GPIO_PINS_13;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Alternate_Output_PP;
			SPI_Config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(GPIOB, &SPI_Config);

			//Setting MISO(Full Duplex / master)
			//PA.14 : SPI2_MISO
			SPI_Config.GPIO_PinNumber = GPIO_PINS_14;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
			MCAL_GPIO_INIT(GPIOB, &SPI_Config);

			//Setting MOSI(Full Duplex / master)
			//PA.15 : SPI1_MOSI
			SPI_Config.GPIO_PinNumber = GPIO_PINS_15;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Alternate_Output_PP;
			SPI_Config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(GPIOB, &SPI_Config);




		}else
		{	//Slave Configuration
			if(GP_SPI_config[SPI2_Index]->NSS == SPI_NSS_HW_Slave){
				//Setting NSS Pin
				//PA.12 : SPI2_NSS
				SPI_Config.GPIO_PinNumber = GPIO_PINS_12;
				SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
				MCAL_GPIO_INIT(GPIOB, &SPI_Config);
			}


			//Setting SCK (Slave)
			//PA.13 : SPI2_SCK
			SPI_Config.GPIO_PinNumber = GPIO_PINS_13;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
			MCAL_GPIO_INIT(GPIOB, &SPI_Config);

			//Setting MISO(Full Duplex / Slave(Point to Point))
			//PA.14 : SPI2_MISO
			SPI_Config.GPIO_PinNumber = GPIO_PINS_14;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Alternate_Output_PP;
			SPI_Config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
			MCAL_GPIO_INIT(GPIOB, &SPI_Config);

			//Setting MOSI(Full Duplex / Slave)
			//PA.15 : SPI2_MOSI
			SPI_Config.GPIO_PinNumber = GPIO_PINS_15;
			SPI_Config.GPIO_Pin_Config = GPIO_CONFIG_Floating_Input;
			MCAL_GPIO_INIT(GPIOB, &SPI_Config);




		}



	}


}


/*=======================================================================================================
 *
 * @Fn    			-MCAL_SPI_SendData
 * @brief			-Send the buffer on SPI
 * @Param[in]		-SPIx: where x can be (1..3 depending on which SPI will be used )
 * @Param[in]		-pTxBuffer: Buffer that we will send the data
 * @Param[in]		-Polling_EN: an enumeration  to check if the polling mechanism is enabled  or not
 *
 *
 * */



void MCAL_SPI_SendData(SPI_typedef* SPIx, uint16_t *pTxBuffer,enum PollingMechanism Polling_EN )
{

	if(Polling_EN == Polling_Enable)
	{
		while( !( (SPIx->SPI_SR) & SPI_SR_TXE ) ){}

	}

	SPIx->SPI_DR = *pTxBuffer;


}







/*=======================================================================================================
 *
 * @Fn    			-MCAL_SPI_ReceiveData
 * @brief			-Receive the buffer from SPI
 * @Param[in]		-SPIx: where x can be (1..3 depending on which SPI will be used )
 * @Param[in]		-pRxBuffer :Buffer that will collect the from Data register
 * @Param[in]		-Polling_EN: an enumeration  to check if the polling mechanism is enabled  or not
 *
 * */



void MCAL_SPI_ReceiveData(SPI_typedef* SPIx, uint16_t *pRxBuffer,enum PollingMechanism Polling_EN )
{

	if(Polling_EN == Polling_Enable)
	{
		while(! ((SPIx->SPI_SR) & SPI_SR_RXNE )){}

	}

	*pRxBuffer = SPIx->SPI_DR;



}



/*=======================================================================================================
 *
 * @Fn    			-MCAL_SPI_TX_RX
 * @brief			-Send and Receive the buffer from SPI
 * @Param[in]		-SPIx: where x can be (1..3 depending on which SPI will be used )
 * @Param[in]		-pTx_RxBuffer : A buffer that will Send the data to Data register and will Collect the data from same Data Register
 * @Param[in]		-Polling_EN: an enumeration  to check if the polling mechanism is enabled  or not
 *
 * */



void MCAL_SPI_TX_RX(SPI_typedef* SPIx, uint16_t *pTx_RxBuffer,enum PollingMechanism Polling_EN )
{
	//Transmitting
	if(Polling_EN == Polling_Enable)
	{
		while( !( (SPIx->SPI_SR) & SPI_SR_TXE ) ){}

	}

	SPIx->SPI_DR = *pTx_RxBuffer;

	//Receiving
	if(Polling_EN == Polling_Enable)
	{
		while(! ((SPIx->SPI_SR) & SPI_SR_RXNE )){}

	}

	*pTx_RxBuffer = SPIx->SPI_DR;



}


//=====================================================
//		                  IRQ
//=====================================================

void SPI1_IRQHandler(void){

	struct S_IRQ_SRC IRQ_SRC;
	IRQ_SRC.TXE = ( (SPI1->SPI_SR & (1<<1)) >> 1);
	IRQ_SRC.RXNE = ( (SPI1->SPI_SR & (1<<0) ) >> 0);
	IRQ_SRC.ERRI = ( (SPI1->SPI_SR & (1<<4) ) >> 4);
	GP_SPI_config [SPI1_Index] ->P_IRQ_CallBack(IRQ_SRC);

}           			/* SPI1 global interrupt   */


void SPI2_IRQHandler(void){

	struct S_IRQ_SRC IRQ_SRC;
	IRQ_SRC.TXE = ( (SPI2->SPI_SR & (1<<1)) >> 1);
	IRQ_SRC.RXNE = ( (SPI2->SPI_SR & (1<<0) ) >> 0);
	IRQ_SRC.ERRI = ( (SPI2->SPI_SR & (1<<4) ) >> 4);
	GP_SPI_config [SPI2_Index] ->P_IRQ_CallBack(IRQ_SRC);

}      	/* SPI2 global interrupt*/





