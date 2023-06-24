/*
 ============================================================================
 Name        : assignment_5_Ex_1_an_illustration_of_how_pointers_work.c
 Author      : Hassan_Attia
 Description : a c program illustrates how pointers work
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

//we will create an integer variable
int X=2;

//Printing the value of X and its address

printf("X=%d\tAddress is:%p\r\n",X, &X);

//now we will create a pointer and this pointer will hold the address of X variable

int* pt_X = &X;


//printing the saved address of pointer pt_X

printf("pointer pt_X created and we assigned the address of X in this pointer\n\r");
printf("pointer pt_X assigned address is %p\r\n", pt_X);

//printing the value of pointer pt_x

printf("value of pointer pt_X = %d\r\n", *pt_X);


//Modifying Value of X through pt_X
printf("modifying value of X to 9 by using pointer pt_X \n\r");

*pt_X = 9;


//printing saved address and value of pt_X



printf("pointer pt_X assigned address is %p\r\n", pt_X);

printf("value of pointer pt_X = %d\n", *pt_X);



	return 0;
}
