/*
 ============================================================================
 Author      : Hassan_Attia
 Description : a program to show how FIFO buffer works
 ============================================================================
 */


#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdint.h"
#include "fifo.h"
int main(void) {
	int i;
	element_type temp;
	//LIFO buffers for UART & I2C
	FIFO_BUF_t UART_buff;
	FIFO_BUF_t I2C_buff ;

	//static allocating array of items
	element_type arr[elements] ;
	//dynamic allocating discrete items
	element_type* arr2 = (element_type*)malloc(elements * sizeof(element_type));

	printf("\n Using static allocation to store items\n");
	fflush(stdout);

	//static  buffer initialising
	FIFO_INIT(&UART_buff, arr, elements);
	printf("\n **********UART FIFO ADD(ENQUEUE)**********\n");
	for(i = 0; i<7 ; i++ ){


		if(FIFO_Enqueue_ITEM(&UART_buff, i) == FIFO_NO_ERROR)
			printf("\nitem[%d] added\n", i );
		else
			printf("\nitem[%d] failed to add.....Buffer Data is full\n",i);

	}


	if(FIFO_PRINT_ITEMS(&UART_buff) == FIFO_NO_ERROR)
	printf("\nUART buffer printed successfully\n");
	fflush(stdout);

	printf("\n****************************\n");
		fflush(stdout);



	printf("\nNow getting items(Dequeue)\n");


	for(i= 0 ; i<5 ; i++){
		if(FIFO_Dequeue_ITEM(&UART_buff,&temp) == FIFO_NO_ERROR){
			printf("\n item[%d] is %d\n", i, temp);
		}
	}



printf("\n----------------------------------------------------------------------------\n");
fflush(stdout);
	 printf("\n Using Dynamic allocation to store items\n");
	fflush(stdout);


	//dynamic buffer initialising
	FIFO_INIT(&I2C_buff, &arr2, elements);
	printf("\n **********I2C FIFO ADD(ENQUEUE)**********\n");
	for(i = 0; i<7 ; i++ ){


		if(FIFO_Enqueue_ITEM(&I2C_buff, i) == FIFO_NO_ERROR)
			printf("\nitem[%d] added\n", i );
		else
			printf("\nitem[%d] failed to add.....Buffer Data is full\n",i);

	}


	if(FIFO_PRINT_ITEMS(&I2C_buff) == FIFO_NO_ERROR)
	printf("\nI2C buffer printed successfully\n");
	fflush(stdout);





	printf("\n****************************\n");
		fflush(stdout);



	printf("\nNow getting items(Dequeue)\n");


	for(i= 0 ; i<5 ; i++){
		if(FIFO_Dequeue_ITEM(&I2C_buff,&temp) == FIFO_NO_ERROR){
			printf("\n item[%d] is %d\n", i, temp);
		}
	}





	//releasing arr2 to protect the ram from over flow
	free(arr2);

	return 0;
}
