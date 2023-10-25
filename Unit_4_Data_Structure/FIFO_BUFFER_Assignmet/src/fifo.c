/*
 * fifo.c
 *
 *  Created on: Oct 18, 2023
 *      Author: hassan
 */

#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stddef.h"

FIFO_STATUS FIFO_INIT(FIFO_BUF_t* buff, element_type* data, element_type length)
{
	//check the existence of FIFO pointers
	if(!buff->base || !buff->head || !buff->tail){
		return FIFO_NULL;
	}
	//Buffer Initialising
	buff->base = data;
	buff->head = data;
	buff->tail = data;
	buff->length = length;
	buff->count = 0;

		return FIFO_NO_ERROR;


}


FIFO_STATUS FIFO_Enqueue_ITEM(FIFO_BUF_t* buff, element_type item)
{
	//check the existence of FIFO pointers
	if(!buff->base || !buff->head || !buff->tail)
		return FIFO_NULL;
	//check if there's a space to add an item or not
	if(buff->count == buff->length)
		return FIFO_FULL;
	// Assigning a value in FIFO buffer data
	*(buff->head) = (element_type)item;
	buff->count++;
	buff->head++;
	// Circular FIFO way to make the head pointer to point on the base which is the beginning of data after adding the last value in array or after exceeding the limit of buffer data
	if( buff->head > ( buff->base + ( buff->length * sizeof(element_type)))){
	buff->head = buff->base;
	buff->count--;}

	return FIFO_NO_ERROR;

}


FIFO_STATUS FIFO_Dequeue_ITEM(FIFO_BUF_t* buff, element_type* item){
	//check the existence of FIFO pointers
	if(!buff->base || !buff->head || !buff->tail)
		return FIFO_NULL;
	//checking on data if it's empty
	if(buff->count == (element_type)0)
		return FIFO_EMPTY;

	*(item) = *(buff->tail);
	buff->count--;
	buff->tail++;
	//we want to ensure that the tail pointer points on the beginning of data after getting the last item in array
	if( buff->tail > ( buff->base + ( buff->length * sizeof(element_type))))
	buff->tail = buff->base;

		return FIFO_NO_ERROR;

}


FIFO_STATUS FIFO_PRINT_ITEMS(FIFO_BUF_t* buff){


	// Checking on Buffer existence
	if(!buff->base || !buff->head )
		return FIFO_NULL;

	// check if buffer empty
	if(buff->count == 0 )
		return FIFO_EMPTY;

	//printing the items
	uint32_t counter = 0;
	uint32_t* temp ;
	temp = buff->tail;
	printf("\n****************************\n");
	fflush(stdout);
	printf("\nprint items.....\n");
	fflush(stdout);
	for(counter = 0 ; counter<buff->count ; counter ++){

		printf("\nitem [%d] is %d\n", counter, *temp);
		temp++;

	}


	fflush(stdout);
	printf("\n****************************\n");
	fflush(stdout);




			return FIFO_NO_ERROR;








}
