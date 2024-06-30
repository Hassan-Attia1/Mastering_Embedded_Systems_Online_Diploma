/*
 * USART.h
 *
 * Created: 4/2/2024 3:14:30 AM
 *  Author: hassan attia
 */ 


#ifndef USART_H_
#define USART_H_


#include "stdlib.h"
#include "stdint.h"
#include "atmega_device_header/atmega32.h"



//USART Pin Configuration
typedef struct
{
	volatile uint16_t Baudrate;	//@ref Baud Rates
	volatile uint8_t Mode_of_Operation;//@ref Asynchronous Operation
	volatile uint8_t Parity;//@ref Parity Modes
	volatile uint8_t Data_Size;//@ref DATA bits
	volatile uint8_t Stop_bits;//@ref Stop Bits
	volatile uint8_t Tx_RX_Enable; //@ref TX_RX_Enabling
	
	
	
	
}USART_PinCfg;



 
//******************MACROS*********************
 
 
 //Baud Rates @ 8MHz crystal 
  #define Baud_2400_N	(uint8_t)207
  #define Baud_4800_N	(uint8_t)103
  #define Baud_9600_N	(uint8_t)25
  #define Baud_14_4_N	(uint8_t)34
 
 
 
 
 //Asynchronous Operation
 #define Asynchronous	0
 #define Synchronous	1
 
 
 //Parity Modes
 
 #define Parity_Disable	(uint8_t)0b00
 #define Parity_Even	(uint8_t)0b10
 #define Parity_Odd		(uint8_t)0b11
 
 //Stop Bits
 #define Stop_1bit	(uint8_t)0
 #define Stop_2bit	(uint8_t)1
 
 
 //DATA bits
 #define five_bits	(uint8_t)0b000 
 #define six_bits	(uint8_t)0b001
 #define seven_bits	(uint8_t)0b010
 #define eight_bits (uint8_t)0b011
 #define nine_bits	(uint8_t)0b111
 

// TX_RX_Enabling
#define TX_RX_Transmit_Only	USART_UCSRB_TXEN
#define TX_RX_Receive_Only	USART_UCSRB_RXEN
#define TX_RX_Transmit_AND_Receive	((uint8_t)(0x3<<3))
  
// USART APIs  

//==================USART APIs=====================

void USART_init(  USART_PinCfg* PinCfg);

void USART_SEND( unsigned char data);

unsigned char  USART_RECIEVE(void);

void USART_SEND_String(uint8_t* String);

#endif /* USART_H_ */