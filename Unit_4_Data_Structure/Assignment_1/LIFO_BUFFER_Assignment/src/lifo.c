/*
 * lifo.c
 *
 *  Created on: Oct 17, 2023
 *      Author: hassa
 */


#include "lifo.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stddef.h"







LIFO_STATUS LIFO_INIT(LIFO_BUF_t* buf, width* items, unsigned int  length){
	// Check Buffer existence
	if(!buf->base || !buf->head)
		return 	LIFO_NULL;
	buf->base = items;
	buf->head = items;
	buf->count = 0;
	buf->length = length;
	return LIFO_NO_ERROR;

}



LIFO_STATUS LIFO_ADD_ITEM(LIFO_BUF_t* buf, width item){
	// Check Buffer existence
	if(!buf->base || !buf->head )
		return LIFO_NULL;
	// Check Buffer if it's full or there's a space you can add an item
	if( buf->count == buf->length )
		return LIFO_FULL;
	// Adding an item
	*(buf->head) = item;
	buf->head++;
	buf->count++;

	return LIFO_NO_ERROR;


}


LIFO_STATUS LIFO_GET_ITEM(LIFO_BUF_t* buf, width* item){

	// Check Buffer existence
	if(!buf->base || !buf->head )
		return LIFO_NULL;
	// Check Buffer if it's empty or not
	if(buf->count == 0)
		return LIFO_EMPTY;
	// getting an item

	buf->head--;
	*(item) = *(buf->head);
	buf->count--;
	return LIFO_NO_ERROR;






}

LIFO_STATUS LIFO_PRINT(LIFO_BUF_t* buf){

	// Checking on Buffer existence
	if(!buf->base || !buf->head )
		return LIFO_NULL;

	// check if buffer empty
	if(buf->count == 0 )
		return LIFO_EMPTY;

	//printing items
	uint32_t counter = 0;
	uint32_t* temp ;
	temp = buf->base;
	printf("\n****************************\n");
	fflush(stdout);
	printf("\nprint items.....\n");
	fflush(stdout);
	for(counter = 0 ; counter<buf->count ; counter ++){

		printf("\nitem [%d] is %d\n", counter, *temp);
		temp++;

	}

	fflush(stdout);
	printf("\n****************************\n");
	fflush(stdout);



	return LIFO_NO_ERROR;
}


