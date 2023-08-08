
#ifndef MY_PLATFORM_TYPES_H
#define MY_PLATFORM_TYPES_H

/*
   s: signed
   u: unsigned
   v: volatile

 */


/*============32-bit integers============*/

typedef int                     sint32_t;
typedef unsigned int            uint32_t;
typedef volatile int            vint32_t;
typedef volatile unsigned int   vuint32_t;

/*========================================*/


/*=============16-bit integers===============*/

typedef short                   sint16_t;
typedef unsigned short          uint16_t;
typedef volatile short          vint16_t;
typedef volatile unsigned short vuint16_t;

/*============================================*/



/*==============8-bit integers====================*/

typedef char                   sint8_t;
typedef unsigned char          uint8_t;
typedef volatile char          vint8_t;
typedef volatile unsigned char vuint8_t;

/*=================================================*/





/*===============Boolean===========================*/
#define TRUE  1
#define FALSE 0
/*==================================================*/



#endif/*MY_PLATFORM_TYPES_H*/


