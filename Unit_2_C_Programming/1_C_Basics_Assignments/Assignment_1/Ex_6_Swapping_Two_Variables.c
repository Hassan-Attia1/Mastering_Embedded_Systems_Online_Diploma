/*
 ============================================================================
 Name        : Ex_6_Swapping_Two_Variables.c
 Author      : Hassan_Attia
 Version     :
 Copyright   : 
 Description : a program to swap two variables using temporary variable
 ============================================================================
 */

#include <stdio.h>
#include <stdio.h>



int main(){

    float x=0,y=0,z=0;

	printf("Enter an value of a:\n");

	fflush(stdin);fflush(stdout);

	scanf("%f",&x);

	printf("Enter an value of b:\n");

		fflush(stdin);fflush(stdout);

		scanf("%f",&y);

       z=x;
       x=y;
       y=z;

       printf("After Swapping,value of a: %0.2f \n",x);

       fflush(stdout);

       printf("After Swapping,value of b: %0.2f \n",y);

}

