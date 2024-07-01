/*
 * Device_header.h
 *
 * Created: 5/24/2024 4:20:02 PM
 *  Author: hassa
 */ 


#ifndef DEVICE_HEADER_H_
 
#define DEVICE_HEADER_H_
 
 
//Crystal Speed


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

//SPI 

#define SPI1_BASE					0x2D

//************************************************
//Peripheral Registers
//************************************************

 

//-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*
//Peripheral Register: GPIO
//-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*


#define PINA		*((volatile uint8_t*)(0x39)) 
#define DDRA		*((volatile uint8_t*)(0x3A))
#define PORTA		*((volatile uint8_t*)(0x3B))
 
#define PINB		*((volatile uint8_t*)(0x36))
#define DDRB		*((volatile uint8_t*)(0x37))
#define PORTB		*((volatile uint8_t*)(0x38))

#define PINC		*((volatile uint8_t*)(0x33))
#define DDRC		*((volatile uint8_t*)(0x34))
#define PORTC		*((volatile uint8_t*)(0x35))

#define PIND		*((volatile uint8_t*)(0x30))
#define DDRD		*((volatile uint8_t*)(0x31))
#define PORTD		*((volatile uint8_t*)(0x32))



//-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*
//Peripheral Register: USART
//-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*
 
 
 #define  UBRRL		*((volatile uint8_t*)(0x29))
 #define  UCSRB		*((volatile uint8_t*)(0x2A))
 #define  UCSRA		*((volatile uint8_t*)(0x2B))
 #define  UDR		*((volatile uint8_t*)(0x2C))
 #define  UBRRH_UCSRC *((volatile uint8_t*)(0x40))
 
 
 
 
 //-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*
 //Peripheral Register: USART
 //-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*-*-*-*_*
 
typedef struct
{
	 volatile uint8_t SPCR;
	 volatile uint8_t SPSR;
	 volatile uint8_t SPDR;
	
	
}SPI_Typedef;
 
//#define SPCR	*((volatile uint8_t*)(0x2D))
//#define SPSR	*((volatile uint8_t*)(0x2E))
//#define SPDR	*((volatile uint8_t*)(0x2F))
 
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


 
 
 
//****************BIT FIELD MACROS FOR SPI***************
//SPI Control Register – SPCR 

//SPR0: SPI Clock Rate Select 0
#define SPI_SPCR_SPR0_POS	(0)
#define SPI_SPCR_SPR0_MASK	(1<<SPI_SPCR_SPR0_POS)
#define SPI_SPCR_SPR0		SPI_SPCR_SPR0_MASK
//SPR1: SPI Clock Rate Select 1
#define SPI_SPCR_SPR1_POS	(1)
#define SPI_SPCR_SPR1_MASK	(1<<SPI_SPCR_SPR1_POS)
#define SPI_SPCR_SPR1		SPI_SPCR_SPR1_MASK
//CPHA: Clock Phase
 #define SPI_SPCR_CPHA_POS	(2)
 #define SPI_SPCR_CPHA_MASK (1<<SPI_SPCR_CPHA_POS)
 #define SPI_SPCR_CPHA		(SPI_SPCR_CPHA_MASK)
//CPOL: Clock Polarity
 #define SPI_SPCR_CPOL_POS		(3)
 #define SPI_SPCR_CPOL_MASK		(1<<SPI_SPCR_CPOL_POS)
 #define SPI_SPCR_CPOL			(SPI_SPCR_CPOL_MASK)
//MSTR: Master/Slave Select
#define SPI_SPCR_MSTR_POS	(4)
#define SPI_SPCR_MSTR_MASK	(1<<SPI_SPCR_MSTR_POS)
#define SPI_SPCR_MSTR		(SPI_SPCR_MSTR_MASK)
 
//DORD: Data Order
#define SPI_SPCR_DORD_POS	(5)
#define SPI_SPCR_DORD_MASK	(1<<SPI_SPCR_DORD_POS)
#define SPI_SPCR_DORD		SPI_SPCR_DORD_MASK
//SPE: SPI Enable
#define SPI_SPCR_SPE_POS	(6)
#define SPI_SPCR_SPE_MASK	(1<<SPI_SPCR_SPE_POS)
#define SPI_SPCR_SPE		(SPI_SPCR_SPE_MASK)
//SPIE: SPI Interrupt Enable
#define SPI_SPCR_SPIE_POS	(7)
#define SPI_SPCR_SPIE_MASK	(1<<SPI_SPCR_SPIE_POS)
#define SPI_SPCR_SPIE		(SPI_SPCR_SPIE_MASK)		
//==============================================================
//SPI Control Register – SPCR 
#define SPI_SPSR_SPI2X_POS	(0)
#define SPI_SPSR_SPI2X_MASK	(1<<SPI_SPSR_SPI2X_POS)
#define SPI_SPSR_SPI2X		(SPI_SPSR_SPI2X_MASK)
//WCOL: Write COLlision Flag (Read Only)
#define SPI_SPSR_WCOL_POS		(6)
#define SPI_SPSR_WCOL_MASK		(1<<SPI_SPSR_WCOL_POS)
#define SPI_SPSR_WCOL			(SPI_SPSR_WCOL_MASK)

//SPIF: SPI Interrupt Flag (Read Only)
#define SPI_SPSR_SPIF_POS	(7)
#define SPI_SPSR_SPIF_MASK	(1<<SPI_SPSR_SPIF_POS)
#define SPI_SPSR_SPIF		(SPI_SPSR_SPIF_MASK) 



//===================Peripheral Instants=================
//USART
#define  USART1				((USART_Typedef*)USART1_BASE)
//SPI
#define SPI1				((SPI_Typedef*)SPI1_BASE)




//-------------------------------
//Some useful Macros
//-------------------------------
#define checkbit(data,bit)	((data>>bit)&1)
#define Setbit(data,bit)	(data|= 1<<bit)
#define Resetbit(data,bit)	(data &= ~(1<<bit))
 





 
#endif /* DEVICE_HEADER_H_ */