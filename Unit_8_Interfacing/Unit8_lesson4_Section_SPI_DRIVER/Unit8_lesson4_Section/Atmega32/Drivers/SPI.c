

#include "SPI.h"













void SPI_INIT( SPI_Typedef* SPIx,SPI_PinCfg* Pinconfig,SPI_MODE mode)
{

//Speed

if(Pinconfig->Double_Speed_enable == Double_Speed_Condition_Disable)
{
	SPIx->SPCR |= (Pinconfig->Speed_Scaler<<SPI_SPCR_SPR0_POS);


}
else//double Speed
{
	SPIx->SPSR |= (SPI_SPSR_SPI2X_POS);
	SPIx->SPCR |= (Pinconfig->Speed_Scaler<<SPI_SPCR_SPR0_POS);

}


if(mode == Master)
{	//MASTER mode
	
	
	
	//Master Mode
	 SPIx->SPCR |= SPI_SPCR_MSTR;
	
	
		
		//SS->PB4   O/P
		DDRB |= (1<<PB4_SS);
		//MOSI->PB5 O/P
		DDRB |= (1<<PB5_MOSI);
		//MISO->PB6 I/P
		
		//SCK->PB7  O/P
		DDRB |= (1<<PB7_SCLK);
	
	//Enabling the Peripheral
	SPIx->SPCR |= Pinconfig->Peripheral_Enable;
	
	
	
	
}
else if (mode == Slave)
{
	
		//Slave Mode
		 SPIx->SPCR &= ~(SPI_SPCR_MSTR);
		 	
		//SS->PB4   I/P
		
		//MOSI->PB5 I/P
		
		//MISO->PB6 O/P
		DDRB|= (1<<PB6_MISO);
		//SCK->PB7  I/P
		
			//Enabling the Peripheral
			SPIx->SPCR |= Pinconfig->Peripheral_Enable;
	
} 





}



 



unsigned char SPI_SEND(SPI_Typedef* SPIx, unsigned char data)
{
	
	 SPIx->SPDR =  data ;
	while( !( ( SPIx->SPSR) & (SPI_SPSR_SPIF) )  );
	return  SPIx->SPDR;
	
	
	 
}



unsigned char SPI_Receive( SPI_Typedef* SPIx,unsigned char  data)
{	uint8_t dummy;
	
	dummy = SPIx->SPSR;
	
	  data = SPIx->SPDR; 
	
	return   data;
	 
	
}