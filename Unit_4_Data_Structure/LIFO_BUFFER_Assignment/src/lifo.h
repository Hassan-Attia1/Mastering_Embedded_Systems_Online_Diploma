/*
 * lifo.h
 *
 *  Created on: Oct 17, 2023
 *      Author: hassan
 */

#ifndef SRC_LIFO_H_
#define SRC_LIFO_H_

#include "stdlib.h"
#include "stdint.h"
#include "stddef.h"
//buffer data type configuration
#define width	uint32_t
#define elements	(width)5


// creating LIFO BUFFER
typedef struct {

	unsigned int* base ;
	unsigned int* head ;
	unsigned int count;
	unsigned int length;


}LIFO_BUF_t;


//status enumeration gives us information about buffer
typedef enum{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL,
}LIFO_STATUS;

LIFO_STATUS LIFO_INIT(LIFO_BUF_t* buf, width* items, unsigned int  buff_length);
LIFO_STATUS LIFO_ADD_ITEM(LIFO_BUF_t* buf, width item);
LIFO_STATUS LIFO_GET_ITEM(LIFO_BUF_t*, width* item);
LIFO_STATUS LIFO_PRINT(LIFO_BUF_t* buf);






#endif /* SRC_LIFO_H_ */
