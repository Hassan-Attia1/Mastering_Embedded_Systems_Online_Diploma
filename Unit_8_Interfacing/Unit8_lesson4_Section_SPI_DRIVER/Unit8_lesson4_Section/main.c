/*
 * Unit8_lesson4_Section.c
 *
 * Created: 5/24/2024 4:17:09 PM
 * Author : hassa
 */ 
 
#include "Atmega32/Drivers/SPI.h"

//#define Master_MODE
//#define Slave_MODE
//#define  Seven_segment

void excute(SPI_Typedef* SPIx,uint8_t cmd, uint8_t data)
{	//Putting slave clock to low
	PORTB &= ~(1<<PB4_SS);
	//Send command
	SPI_SEND(SPI1,cmd);
	
 
	//Send The data
	
	SPI_SEND(SPI1,data);
	
 
	//Put slave clock on high
	
	PORTB |= (1<<PB4_SS);

}


int main(void)
{
#ifdef Master_MODE

SPI_PinCfg SPI_Master;
SPI_Master.Double_Speed_enable = Double_Speed_Condition_Disable;
SPI_Master.Peripheral_Enable = Peripheral_Condition_Enable;
SPI_Master.Speed_Scaler = Prescle_16;
SPI_INIT( SPI1,&SPI_Master,Master);

#endif
	
#ifdef Slave_MODE
SPI_PinCfg SPI_Slave;
SPI_Slave.Double_Speed_enable = Double_Speed_Condition_Disable;
SPI_Slave.Peripheral_Enable = Peripheral_Condition_Enable;
SPI_Slave.Speed_Scaler = Prescle_16;
SPI_INIT( SPI1,&SPI_Slave,Slave);
DDRA |= 0xFF;
unsigned char data ;

for(data = 0 ; data <=10 ; data++)
{	_delay_ms(1000);
	PORTA = SPI_SEND( SPI1,&data) &0x0f  ;
	_delay_ms(1000);
}
#endif

//#ifdef Seven_segment
SPI_PinCfg SPI_Master;
SPI_Master.Double_Speed_enable = Double_Speed_Condition_Disable;
SPI_Master.Peripheral_Enable = Peripheral_Condition_Enable;
SPI_Master.Speed_Scaler = Prescle_16;
SPI_INIT( SPI1,&SPI_Master,Master);

uint8_t counter = 0;
uint32_t index_display  ;
excute(SPI1,0x09,0xFF);//Decode all displays 11111111
excute(SPI1,0x0B,0x07);//Set scan limit (digit 0 to digit 7)
excute(SPI1,0x0A,0x0F);//Max intensity
excute(SPI1,0x0C,0x01);//Turn on the display

while(1)
{
	for(index_display = 1 ; index_display<9; index_display++)
	{
		excute(SPI1,index_display,counter++);
_delay_ms(1000);

	} 
	
	
	
	
}


//#endif
}

