/*
 * SPI.h
 *
 * Created: 5/24/2024 4:19:12 PM
 *  Author: hassa
 */ 


#ifndef SPI_H_
#define SPI_H_


/*
 * SPI.c
 *
 * Created: 5/24/2024 4:18:58 PM
 *  Author: hassa
 */ 



 #define  F_CPU 1000000UL

#include "util/delay.h"
#include "stdint.h"
#include "Device_header.h"

//Enums

typedef enum
{
	Master,
	Slave
	}SPI_MODE;



typedef struct
{
	
	
	uint8_t Peripheral_Enable;
	
	uint8_t	Speed_Scaler;
	
	uint8_t Double_Speed_enable;
	
	
}SPI_PinCfg;




//@ref Peripheral_Condition

#define  Peripheral_Condition_Disable	0
#define  Peripheral_Condition_Enable	SPI_SPCR_SPE

//@ref Speed frequency prescaler
#define Prescle_4	((uint8_t)0x0)
#define Prescle_16	((uint8_t)0x1)
#define Prescle_64	((uint8_t)0x2)
#define Prescle_128 ((uint8_t)0x3)
#define Prescle_2	((uint8_t)0x0)
#define Prescle_8	((uint8_t)0x1)
#define Prescle_32	((uint8_t)0x2)
#define Prescle_64_double  ((uint8_t)0x3)

//@ref Double_Speed_Condition

#define Double_Speed_Condition_Disable	0
#define Double_Speed_Condition_Enable	1






//Pins Access 
#define  PB4_SS	4
#define  PB5_MOSI 5
#define  PB6_MISO 6
#define  PB7_SCLK 7














//=========================SPI APIs======================


void SPI_INIT( SPI_Typedef* SPIx,SPI_PinCfg* Pinconfig,SPI_MODE mode);
unsigned char SPI_SEND( SPI_Typedef* SPIx,unsigned char  data);
unsigned char SPI_Receive( SPI_Typedef* SPIx,unsigned char  data);
#endif /* SPI_H_ */