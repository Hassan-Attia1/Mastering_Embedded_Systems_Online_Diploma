/*
 ============================================================================
 Name        : LIFO_BUFFER_Assignment.c
 Author      : Hassan_Attia
 Description : program illustrates how LIFO algorithm works
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stddef.h"
#include "lifo.h"




int main(void) {
	int i;
	width temp =0;
	//LIFO buffers for UART & I2C
	LIFO_BUF_t UART_buff;
	LIFO_BUF_t I2C_buff ;

	//static allocating array of items
	width arr[elements] ;
	//dynamic allocating discrete items
	width* arr2 = (width*)malloc(elements * sizeof(width));

	printf("\n Using static allocation to store items\n");
	fflush(stdout);

	//static  buffer initialising
	LIFO_INIT(&UART_buff, arr, elements);
	printf("\n**********LIFO ADD(PUSH)**********\n");
	for(i = 0; i<7 ; i++ ){


		if(LIFO_ADD_ITEM(&UART_buff, i) == LIFO_NO_ERROR)
			printf("\nitem[%d] added\n", i );
		else
			printf("\nitem[%d]failed to add.....Buffer Data is full\n",i);

	}


	LIFO_PRINT(&UART_buff);

	fflush(stdout);
	printf("\nGetting items(pop)...\n");
	fflush(stdout);


	for(i= 0 ; i<5 ; i++){
		if(LIFO_GET_ITEM(&UART_buff,&temp) == LIFO_NO_ERROR){
			printf("\n item[%d] is %d\n", i, temp);
		}
	}




printf("\n----------------------------------------------------------------------------\n");
fflush(stdout);

 	printf("\n Using Dynamic allocation to store items\n");
	fflush(stdout);


	//dynamic buffer initialising
	LIFO_INIT(&I2C_buff, &arr2, elements);
	printf("\n**********LIFO ADD(PUSH)**********\n");
	for(i = 0; i<7 ; i++ ){


		if(LIFO_ADD_ITEM(&I2C_buff, i) == LIFO_NO_ERROR)
			printf("\nitem[%d] added\n", i );
		else
			printf("\nitem[%d] filed to add.....Buffer Data is full\n",i);

	}


	LIFO_PRINT(&I2C_buff);

	for(i= 0 ; i<5 ; i++){
		if(LIFO_GET_ITEM(&I2C_buff,&temp) == LIFO_NO_ERROR){
			printf("\n item[%d] is %d\n", i, temp);
		}
	}






	//releasing arr2 to protect the ram from over flow
	free(arr2);

	return 0;
}
