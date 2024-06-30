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





void USART_init( USART_PinCfg* PinCfg)
{
	//Save a backup for Pin configuration
	GP_USART_Config[USART1_Index] = *PinCfg;
	//Set Baudrate @ Frequency = 8MHz
	 UBRRL |= PinCfg->Baudrate;
	//=====Set Frame
	//Data size
	
	UBRRH_UCSRC |= USART_UCSRC_URSEL;
	
	if(PinCfg->Data_Size == five_bits)
	{
		 UCSRB &= ~(USART_UCSRB_UCSZ2);
		UBRRH_UCSRC &= ~(USART_UCSRC_UCSZ0);
		UBRRH_UCSRC &= ~(USART_UCSRC_UCSZ1);
	}
	else if(PinCfg->Data_Size == six_bits)
	{
		 UCSRB &= ~(USART_UCSRB_UCSZ2);
		UBRRH_UCSRC |= (USART_UCSRC_UCSZ0);
		UBRRH_UCSRC &= ~(USART_UCSRC_UCSZ1);
	}
	else if(PinCfg->Data_Size == seven_bits)
	{
			 UCSRB &= ~(USART_UCSRB_UCSZ2);
			UBRRH_UCSRC &= ~(USART_UCSRC_UCSZ0);
			UBRRH_UCSRC |= (USART_UCSRC_UCSZ1);
	}
	else if(PinCfg->Data_Size == eight_bits)
	{
			 UCSRB &= ~(USART_UCSRB_UCSZ2);
			UBRRH_UCSRC |= (USART_UCSRC_UCSZ0|USART_UCSRC_UCSZ1);
		 
	}
	else if(PinCfg->Data_Size == nine_bits)
	{
			 UCSRB |= (USART_UCSRB_UCSZ2);
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
		UBRRH_UCSRC &= ~(USART_UCSRC_UCPOL);
		 UCSRA &= ~(USART_UCSRA_U2X);
		 
	}
	else//synchronous
	{
		UBRRH_UCSRC |= (USART_UCSRC_UMSEL);
		UCSRA |= (USART_UCSRA_U2X);
	}
	
	if(PinCfg->Tx_RX_Enable == TX_RX_Receive_Only)
	{
		 UCSRB |=	USART_UCSRB_RXEN;
	}
	else if(PinCfg->Tx_RX_Enable == TX_RX_Transmit_Only)
	{
		 UCSRB |=	USART_UCSRB_TXEN;
		
	}
	else  //TX_RX both are enable
	{
	 UCSRB |=	(USART_UCSRB_TXEN|USART_UCSRB_RXEN);
		
	}
	
	

	
	
	
	
	
	
}




	
	
	
	/*=======================================================================================================
 *
 * @Fn    			-USART_SEND
 * @brief			-This is used to Send data from tx to rx
 * @Param[in]		-None
 * @retval			-None
 * */





void USART_SEND(unsigned char data){
	
	while( !( ( UCSRA) & USART_UCSRA_UDRE ) );//we used this check to see if the data register is empty or not
	
	 
	 UDR  = data;
	
	
}



/*=======================================================================================================
 *
 * @Fn    			-USART_RECIEVE
 * @brief			-Receiving a buffer from externals
 * @Param[in]		-None
 * @retval			-a buffer for receiving the data from external peripheral
 * */



unsigned char  USART_RECIEVE(void){

	if (  UCSRA & ( (USART_UCSRA_FE) || (USART_UCSRA_DOR) ) )    //if there is error return null
	return '\0';


	while	( !( (UCSRA) & USART_UCSRA_RXC )) ; // check if the receiving buffer is empty or not
	return  UDR;
 
}  




/*=======================================================================================================
 *
 * @Fn    			-USART_SEND_String
 * @brief			-Send a string 
 * @Param[in]		-None
 * @retval			-None
 * */



void USART_SEND_String(uint8_t* String)
{ 
	while(*String)
	{
		USART_SEND(*String);
		String++;
	}
	
	
	
}




