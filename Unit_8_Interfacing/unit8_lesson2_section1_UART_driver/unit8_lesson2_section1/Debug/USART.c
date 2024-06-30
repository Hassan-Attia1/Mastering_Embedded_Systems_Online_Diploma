/*
 * USART.c
 *
 * Created: 4/2/2024 3:14:08 AM
 *  Author: hassa
 */ 





#include "USART.h"







/*
==============================Generic Functions===========================
*/

		

/*
==============================Generic Macros===========================
*/
#define USART1_Index	0


/*
==============================Pin Configuration===========================
*/


/*
============================== Generic Variables===========================
*/

USART_PinCfg  GP_USART_Config  [1] = {{NULL}};







/*=======================================================================================================
 *
 * @Fn    			-USART_init
 * @brief			-This is used to initialize USART by setting the baud rate & frame data & enabling the transmit and receive  
 * @Param[in]		-USARTx
 * @Param[in]		-PinCfg
 * @retval			-None
 */





void USART_init(USART_Typedef* USARTx, USART_PinCfg* PinCfg)
{
	//Save a backup for Pin configuration
	GP_USART_Config[USART1_Index] = *PinCfg;
	//Set Baudrate @ Frequency = 8MHz
	USARTx->UBRRL |= PinCfg->Baudrate;
	//=====Set Frame
	//Data size
	if(PinCfg->Data_Size == five_bits)
	{
		USARTx->UCSRB &= ~(USART_UCSRB_UCSZ2);
		UBRRH_UCSRC &= ~(USART_UCSRC_UCSZ0);
		UBRRH_UCSRC &= ~(USART_UCSRC_UCSZ1);
	}
	else if(PinCfg->Data_Size == six_bits)
	{
		USARTx->UCSRB &= ~(USART_UCSRB_UCSZ2);
		UBRRH_UCSRC |= (USART_UCSRC_UCSZ0);
		UBRRH_UCSRC &= ~(USART_UCSRC_UCSZ1);
	}
	else if(PinCfg->Data_Size == seven_bits)
	{
			USARTx->UCSRB &= ~(USART_UCSRB_UCSZ2);
			UBRRH_UCSRC &= ~(USART_UCSRC_UCSZ0);
			UBRRH_UCSRC |= (USART_UCSRC_UCSZ1);
	}
	else if(PinCfg->Data_Size == eight_bits)
	{
			USARTx->UCSRB &= ~(USART_UCSRB_UCSZ2);
			UBRRH_UCSRC |= (USART_UCSRC_UCSZ0);
			UBRRH_UCSRC |= (USART_UCSRC_UCSZ1);
	}
	else if(PinCfg->Data_Size == nine_bits)
	{
			USARTx->UCSRB |= (USART_UCSRB_UCSZ2);
			UBRRH_UCSRC |= (USART_UCSRC_UCSZ0);
			UBRRH_UCSRC |= (USART_UCSRC_UCSZ1);
	}
	//Parity
	if(PinCfg->Parity == Parity_Disable)
	{
		UBRRH_UCSRC &= ~(USART_UCSRC_UPM0);
		UBRRH_UCSRC &= ~(USART_UCSRC_UPM1);
		
	}
	else if(PinCfg->Parity == Parity_Even)
	{
		UBRRH_UCSRC &= ~(USART_UCSRC_UPM0);
		UBRRH_UCSRC |=  (USART_UCSRC_UPM1);
	}
	else if(PinCfg->Parity == Parity_Odd)
	{
		UBRRH_UCSRC |= (USART_UCSRC_UPM0);
		UBRRH_UCSRC |= (USART_UCSRC_UPM1);
	}
	//Stop bits
	if(PinCfg->Stop_bits == Stop_1bit)
	{
		UBRRH_UCSRC &= ~(USART_UCSRC_USBS);
	}
	else
	{
		UBRRH_UCSRC |= (USART_UCSRC_USBS);
	}
	//------------------
	//Set Mode
	if(PinCfg->Mode_of_Operation == Asynchronous)
	{
		UBRRH_UCSRC &= ~(USART_UCSRC_UMSEL);
		USARTx->UCSRA |= (USART_UCSRA_U2X);
	}
	else//synchronous
	{
		UBRRH_UCSRC |= (USART_UCSRC_UMSEL);
		USARTx->UCSRA &= ~(USART_UCSRA_U2X);
	}
	
	//Enabling Tx & Rx
	#define TX_RX_Transmit_Only	USART_UCSRB_TXEN
	#define TX_RX_Receive_Only	USART_UCSRB_RXEN
	#define TX_RX_Transmit_AND_Receive	((uint8_t)(0x3<<3))
	
	if(PinCfg->Tx_RX_Enable == TX_RX_Receive_Only)
	{
		USARTx->UCSRB |=	USART_UCSRB_RXEN;
	}
	else if(PinCfg->Tx_RX_Enable == TX_RX_Transmit_Only)
	{
		USARTx->UCSRB |=	USART_UCSRB_TXEN;
		
	}
	else//TX_RX both are enable
	{
		USARTx->UCSRB |=	USART_UCSRB_TXEN;
		USARTx->UCSRB |=	USART_UCSRB_RXEN;
		
	}
	
	

	
	
	
	
	
	
}




	
	
	
	/*=======================================================================================================
 *
 * @Fn    			-USART_SEND
 * @brief			-This is used to Send data from tx to rx
 * @Param[in]		-None
 * @retval			-None
 * */





void USART_SEND(USART_Typedef* USARTx,unsigned char data){
	
	while( !( (USARTx->UCSRA) & USART_UCSRA_UDRE ) );//we used this check to see if the data register is empty or not
	
	 
	USARTx->UDR |= (uint8_t)data;
	
	
}



/*=======================================================================================================
 *
 * @Fn    			-USART_RECIEVE
 * @brief			-This is used to initialize EXTI from specific GPIO Pin and specify the Mask/Trigger condition and IRQ Callback
 * @Param[in]		-None
 * @retval			-None
 * */



unsigned char  USART_RECIEVE(USART_Typedef* USARTx){

	while	( !( (USARTx->UCSRA) & USART_UCSRA_RXC )) ; // check if the receiving buffer is empty or not
	return USARTx->UDR;

}  









