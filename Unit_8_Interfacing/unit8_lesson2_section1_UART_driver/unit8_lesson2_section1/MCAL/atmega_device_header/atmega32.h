/*
 * atmega32.h
 *
 * Created: 4/2/2024 10:07:44 PM
 *  Author: hassa
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

 
//Crystal Speed
#define F_CPU 4000000UL



//-------------------
//Includes
//-------------------

#include "stdlib.h"
#include "stdint.h"
//#include "avr/io.h"
#include "util/delay.h"
//#include "util/setbaud.h"



//-------------------------------
//Base Addresses For memories
//-------------------------------

#define FLASH_MEMORY_BASE						0x0000
#define SRAM_MEMORY_BASE						0x0060

 
//-------------------------------
//Base addresses for AHB Peripherals
//-------------------------------

//USART

#define USART1_BASE					0x29


//************************************************
//Peripheral Registers
//************************************************

 

//-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*
//Peripheral Register: GPIO
//-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*


#define PINA		*(volatile uint8_t*)(0x39) 
#define DDRA		*(volatile uint8_t*)(0x3A)
#define PORTA		*(volatile uint8_t*)(0x3B)
 
#define PINB		*(volatile uint8_t*)(0x36)
#define DDRB		*(volatile uint8_t*)(0x37)
#define PORTB		*(volatile uint8_t*)(0x38)

#define PINC		*(volatile uint8_t*)(0x33)
#define DDRC		*(volatile uint8_t*)(0x34)
#define PORTC		*(volatile uint8_t*)(0x35)

#define PIND		*(volatile uint8_t*)(0x30)
#define DDRD		*(volatile uint8_t*)(0x31)
#define PORTD		*(volatile uint8_t*)(0x32)



//-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*
//Peripheral Register: USART
//-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*
 
 
 #define  UBRRL		*((volatile uint8_t*)(0x29))
 #define  UCSRB		*((volatile uint8_t*)(0x2A))
 #define  UCSRA		*((volatile uint8_t*)(0x2B))
 #define  UDR		*((volatile uint8_t*)(0x2C))
 #define  UBRRH_UCSRC *((volatile uint8_t*)(0x40))
 
//****************BIT FIELD MACROS FOR USART***************

//UCSRA:USART Control and Status Register A
//  Multi-processor Communication Mode
#define USART_UCSRA_MPCM_POS	0
#define USART_UCSRA_MPCM_MASK	((uint8_t)0x1<<USART_UCSRA_MPCM_POS)
#define USART_UCSRA_MPCM		USART_UCSRA_MPCM_MASK
//  Double the USART Transmission Speed
#define USART_UCSRA_U2X_POS		1
#define USART_UCSRA_U2X_MASK	((uint8_t)0x1<<USART_UCSRA_U2X_POS)
#define USART_UCSRA_U2X			USART_UCSRA_U2X_MASK
//	Parity Error
#define USART_UCSRA_PE_POS		2
#define USART_UCSRA_PE_MASK		((uint8_t)0x1<<USART_UCSRA_PE_POS)
#define USART_UCSRA_PE			USART_UCSRA_PE_MASK
//	Data OverRun
#define USART_UCSRA_DOR_POS		3
#define USART_UCSRA_DOR_MASK	((uint8_t)0x1<<USART_UCSRA_DOR_POS)
#define USART_UCSRA_DOR			USART_UCSRA_DOR_MASK
//	Frame Error
#define USART_UCSRA_FE_POS		4
#define USART_UCSRA_FE_MASK		((uint8_t)0x1<<USART_UCSRA_FE_POS)
#define USART_UCSRA_FE			USART_UCSRA_FE_MASK
//	USART Data Register Empty
#define USART_UCSRA_UDRE_POS	5
#define USART_UCSRA_UDRE_MASK	((uint8_t)0x1<<USART_UCSRA_UDRE_POS)
#define USART_UCSRA_UDRE		USART_UCSRA_UDRE_MASK
//  USART Transmit Complete
#define USART_UCSRA_TXC_POS		6
#define USART_UCSRA_TXC_MASK	((uint8_t)0x1<<USART_UCSRA_TXC_POS)
#define USART_UCSRA_TXC			USART_UCSRA_MPCM_TXC
//	USART Receive Complete
#define USART_UCSRA_RXC_POS		7
#define USART_UCSRA_RXC_MASK	((uint8_t)0x1<<USART_UCSRA_RXC_POS)
#define USART_UCSRA_RXC			USART_UCSRA_RXC_MASK
 
 
 //UCSRB:USART Control and Status Register B
 //Transmit Data Bit 8
 #define USART_UCSRB_TXB8_POS		0
 #define USART_UCSRB_TXB8_MASK		((uint8_t)0x1<<USART_UCSRB_TXB8_POS)
 #define USART_UCSRB_TXB8			USART_UCSRB_TXB8
 //Receive Data Bit 8
 #define USART_UCSRB_RXB8_POS		1
 #define USART_UCSRB_RXB8_MASK		((uint8_t)0x1<<USART_UCSRB_RXB8_POS)
 #define USART_UCSRB_RXB8			USART_UCSRB_RXB8_MASK
 //Character Size
 #define USART_UCSRB_UCSZ2_POS		2
 #define USART_UCSRB_UCSZ2_MASK		((uint8_t)0x1<<USART_UCSRB_UCSZ2_POS)
 #define USART_UCSRB_UCSZ2			USART_UCSRB_UCSZ2_MASK
 //Transmitter Enable
 #define USART_UCSRB_TXEN_POS		3
 #define USART_UCSRB_TXEN_MASK		((uint8_t)0x1<<USART_UCSRB_TXEN_POS)
 #define USART_UCSRB_TXEN			USART_UCSRB_TXEN_MASK
 //Receiver Enable
 #define USART_UCSRB_RXEN_POS		4
 #define USART_UCSRB_RXEN_MASK		((uint8_t)0x1<<USART_UCSRB_RXEN_POS)
 #define USART_UCSRB_RXEN			USART_UCSRB_RXEN_MASK
 //USART Data Register Empty Interrupt Enable
 #define USART_UCSRB_UDRIE_POS		5
 #define USART_UCSRB_UDRIE_MASK		((uint8_t)0x1<<USART_UCSRB_UDRIE_POS)
 #define USART_UCSRB_UDRIE			USART_UCSRB_UDRIE_MASK
 //TX Complete Interrupt Enable
 #define USART_UCSRB_TXCIE_POS		6
 #define USART_UCSRB_TXCIE_MASK		((uint8_t)0x1<<USART_UCSRB_TXCIE_POS)
 #define USART_UCSRB_TXCIE			USART_UCSRB_TXCIE_MASK
 //RX Complete Interrupt Enable
 #define USART_UCSRB_RXCIE_POS		7
 #define USART_UCSRB_RXCIE_MASK		((uint8_t)0x1<<USART_UCSRB_RXCIE_POS)
 #define USART_UCSRB_RXCIE			USART_UCSRB_RXCIE_MASK
 
 
 
 
 
 
 
//UCSRC:USART Control and Status Register C
//Clock Polarity
#define USART_UCSRC_UCPOL_POS		0
#define USART_UCSRC_UCPOL_MASK		((uint8_t)0x1<<USART_UCSRC_UCPOL_POS)
#define USART_UCSRC_UCPOL			USART_UCSRC_UCPOL_MASK
//Character Size
#define USART_UCSRC_UCSZ0_POS		1
#define USART_UCSRC_UCSZ0_MASK		((uint8_t)0x1<<USART_UCSRC_UCSZ0_POS)
#define USART_UCSRC_UCSZ0			USART_UCSRC_UCSZ0_MASK
//Character Size
#define USART_UCSRC_UCSZ1_POS		2
#define USART_UCSRC_UCSZ1_MASK		((uint8_t)0x1<<USART_UCSRC_UCSZ1_POS)
#define USART_UCSRC_UCSZ1			USART_UCSRC_UCSZ1_MASK
//Stop Bit Select
#define USART_UCSRC_USBS_POS		3
#define USART_UCSRC_USBS_MASK		((uint8_t)0x1<<USART_UCSRC_USBS_POS)
#define USART_UCSRC_USBS			USART_UCSRC_USBS_MASK
//Parity Mode
#define USART_UCSRC_UPM0_POS		4
#define USART_UCSRC_UPM0_MASK		((uint8_t)0x1<<USART_UCSRC_UPM0_POS)
#define USART_UCSRC_UPM0			USART_UCSRC_UPM0_MASK
//Parity Mode
#define USART_UCSRC_UPM1_POS		5
#define USART_UCSRC_UPM1_MASK		((uint8_t)0x1<<USART_UCSRC_UPM1_POS)
#define USART_UCSRC_UPM1			USART_UCSRC_UPM1_MASK
//USART Mode Select
#define USART_UCSRC_UMSEL_POS		6
#define USART_UCSRC_UMSEL_MASK		((uint8_t)0x1<<USART_UCSRC_UMSEL_POS)
#define USART_UCSRC_UMSEL			USART_UCSRC_UMSEL_MASK
//Register Select	0-->UBRRH	1-->UCSRC
#define USART_UCSRC_URSEL_POS		7
#define USART_UCSRC_URSEL_MASK		((uint8_t)0x1<<USART_UCSRC_URSEL_POS)
#define USART_UCSRC_URSEL			USART_UCSRC_URSEL_MASK


 
//==============================================================













//===================Peripheral Instants=================

#define  USART1				((USART_Typedef*)USART1_BASE)






//-------------------------------
//Some useful Macros
//-------------------------------
#define checkbit(data,bit)	((data>>bit)&1)
#define Setbit(data,bit)	(data|= 1<<bit)
#define Resetbit(data,bit)	(data &= ~(1<<bit))
 
































#endif /* ATMEGA32_H_ */