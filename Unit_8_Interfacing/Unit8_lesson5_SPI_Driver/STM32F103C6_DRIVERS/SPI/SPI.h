/*
 * SPI.h
 *
 *  Created on: Apr 20, 2024
 *      Author: hassa
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_


//Includes
#include "GPIO/stm32_F103C6_gpio_driver.h"
#include "EXTI/stm32_F103C6_EXTI_driver.h"
#include "Device_header/stm32f103x6.h"


//Configuration structure


struct S_IRQ_SRC{
	uint8_t TXE:1 ;//Tx Buffer empty interrupt
	uint8_t RXNE:1 ; //RX Buffer not empty interrupt
	uint8_t ERRI:1 ; //Error Interrupt
	uint8_t reserved:5;

};


typedef struct
{


	uint16_t	Device_Mode;				//Specifies the SPI operating mode
											//This member must be set based on @ref SPI_Device_Mode

	uint16_t	Communitcation_Mode;		//Specifies the communication mode
											//This member must be set based on @ref SPI_Communication_Mode

	uint16_t	Data_Size;					//Specifies what size of data will be sent
											//This member must be set based on @ref SPI_Data_Size

	uint16_t    Frame_Format;				//Specifies which will be sent the LSB or MSB
											//This member must be set based on @ref SPI_Frame_Format

	uint16_t	CLK_Polarity;				//Specifies the steady state value of clock when no data is being transferred
											//This member must be set based on @ref SPI_CLK_Polarity

	uint16_t	CLK_Phase;					//Specifies which edge will be used as strobe to send/receive data
											//This member must be set based on @ref SPI_CLK_Phase

	uint16_t	NSS;						//Specifies if the NSS signal will be controlled
											// by Hardware or Software using the SSI bit_enable
											// This member must be set based on @ref SPI_NSS_Type

	uint16_t	SPI_Baud_Rate_Scaler;		//Specifies Baud Rate prescaler value which will be used to Configure TX/RX SCK
											//This member must be set based on @ref SPI_Baud_Rate_Prescaler
											//|Note|: The communication clock is derived from the master clock . The slave dosen't need to be set
											//|Note|; You have to configure RCC to enter the correct clock for either SPI1 --> APB2 or SPI2--> APB1

	uint16_t	IRQ_Enable;					//Specifies whether if you want to enable the interrupt or not
											//This member must be set based on @ref SPI_IRQ_Enable

	void (*P_IRQ_CallBack)(struct S_IRQ_SRC);//Set the C function() in app layer which will be called once the IRQ happen




}SPI_Config;





//------------------------------------------
//=======SPI REFERENCE MACROS======
//------------------------------------------

//	@ref SPI_Device_Mode
#define SPI_Device_Mode_SLAVE								(0x00000000UL)
#define SPI_Device_Mode_Master								(0x1UL<<2) //CR1.Bit 2 ->MSTR: Master selection

//	@ref SPI_Communication_Mode
#define SPI_Direction_2Lines 								(0x00000000UL)
#define SPI_Direction_2Lines_RX_only						(0x1UL<<10)//CR1.Bit 10 ->RXONLY:Recevier Only
#define SPI_Direction_1Lines_RX_only						(0x1UL<<15)//CR1.Bit 15 ->BIDIMODE: Bidirectional data mode enable
#define SPI_Direction_1Lines_TX_only						((0x1UL<<15) | (0x1UL<<14))//CR1.Bit 15 ->BIDIMODE: Bidirectional data mode enable & CR1.Bit 14  BIDIOE: Output enable in bidirectional mode

//  @ref SPI_Data_Size
#define SPI_DATASize_8BIT									(0x00000000UL)
#define SPI_DATASize_16BIT									(0x1UL<<11)//CR1.Bit 11 ->DFF: Data frame format

//	@ref SPI_Frame_Format
#define SPI_Frame_Format_MSB_transmitted_first				 (0x0UL)
#define SPI_Frame_Format_LSB_transmitted_first				 (0x1UL<<7)//CR1.Bit 7  ->LSBFIRST: Frame format


//	@ref SPI_CLK_Polarity
#define SPI_CLK_Polarity_Zero_Idle							(0x00000000UL)
#define SPI_CLK_Polarity_One_Idle							(0x1UL<<1)//CR1.Bit 1   ->CPOL: Clock polarity


//  @ref SPI_CLK_Phase
#define SPI_CLK_Phase_First_Edge_Capture					(0x00000000UL)
#define SPI_CLK_Phase_Second_Edge_Capture					(0x1UL<<0)//CR1.Bit 0	->CPHA: Clock phase

//  @ref SPI_NSS_Type	Slave Select Management

//NSS is driven by Hardware(Master or Slave)
#define SPI_NSS_HW_Slave									(0x00000000UL)
#define SPI_NSS_HW_Master_Output_disable					~(0x1UL<<2)
#define SPI_NSS_HW_Master_Output_Enable						(0x1UL<<2)//CR2.Bit 2 ->SSOE: SS output enable

//NSS is driven by Software(Master or Slave)
#define SPI_NSS_SW_SSI_not_Set								(0x1UL<<9)//CR1.Bit 9 -> SSM: Software slave management
#define SPI_NSS_SW_SSI_Set									((0x1UL<<9) |  (0x1UL<<8) )//CR1.Bit 9 -> SSM: Software slave management	& CR1.Bit 8 -> SSI: Internal slave select

//  @ref SPI_Baud_Rate_Prescaler

#define SPI_BaudRate_Prescaler_Divided_by_2					(0x00000000UL)
#define SPI_BaudRate_Prescaler_Divided_by_4					(0b001UL<<3)
#define SPI_BaudRate_Prescaler_Divided_by_8					(0b010UL<<3)
#define SPI_BaudRate_Prescaler_Divided_by_16				(0b011UL<<3)
#define SPI_BaudRate_Prescaler_Divided_by_32				(0b100UL<<3)
#define SPI_BaudRate_Prescaler_Divided_by_64				(0b101UL<<3)
#define SPI_BaudRate_Prescaler_Divided_by_128				(0b110UL<<3)
#define SPI_BaudRate_Prescaler_Divided_by_256				(0b111UL<<3)


//@ref SPI_IRQ_Enable
#define SPI_IRQ_Enable_None						(0x00000000UL)
#define SPI_IRQ_Enable_TXEIE					(0x1UL<<7)//CR2.Bit 7 ->TXEIE: Tx buffer empty interrupt enable
#define SPI_IRQ_Enable_RXNEIE					(0x1UL<<6)//CR2.Bit 6 ->RXNEIE: RX buffer not empty interrupt enable
#define SPI_IRQ_Enable_ERRIE					(0x1UL<<5)//CR2.Bit 5 ->ERRIE: Error interrupt enable


//Enums
enum PollingMechanism{
	Polling_Enable,
	Polling_Disable
};


//=====================================================
//		APIs Supported by "MCAL SPI DRIVER"
//=====================================================


void MCAL_SPI_Init (SPI_typedef* SPIx, SPI_Config* SPI_Config);
void MCAL_SPI_DeInit (SPI_typedef* SPIx);
void MCAL_SPI_GPIO_Set_Pins(SPI_typedef* SPIx);
void MCAL_SPI_SendData(SPI_typedef* SPIx, uint16_t *pTxBuffer,enum PollingMechanism Polling_EN );
void MCAL_SPI_ReceiveData(SPI_typedef* SPIx, uint16_t *pRxBuffer,enum PollingMechanism Polling_EN );
void MCAL_SPI_TX_RX(SPI_typedef* SPIx, uint16_t *pTx_RxBuffer,enum PollingMechanism Polling_EN );























#endif /* SPI_SPI_H_ */
