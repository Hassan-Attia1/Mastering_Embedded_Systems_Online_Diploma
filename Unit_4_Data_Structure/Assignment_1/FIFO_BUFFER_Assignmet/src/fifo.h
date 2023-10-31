/*
 * fifo.h
 *
 *  Created on: Oct 18, 2023
 *      Author: hassan
 */

#ifndef FIFO_H_
#define FIFO_H_

//libraries
#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdint.h"

//configuration settings :
#define element_type	uint32_t
#define elements	(element_type)5


//setting FIFO buffer

typedef struct{

	unsigned int* head; //to add an item
	unsigned int* tail; //to get an item
	unsigned int* base; //to point on the first item in FIFO buffer
	unsigned int count; //to inform us how many items were added
	unsigned int length;//buffer data length



}FIFO_BUF_t;




//setting enumeration to show status about FIFO
typedef enum{

	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL

}FIFO_STATUS;



//Functions Definitions


FIFO_STATUS FIFO_INIT(FIFO_BUF_t* buff, element_type* data, element_type length);

FIFO_STATUS FIFO_Enqueue_ITEM(FIFO_BUF_t* buff, element_type item);

FIFO_STATUS FIFO_Dequeue_ITEM(FIFO_BUF_t* buff, element_type* item);

FIFO_STATUS FIFO_PRINT_ITEMS(FIFO_BUF_t* buff);




#endif /* FIFO_H_ */
