/*
 ==================================================================================
 Name        : Ex_7_Swapping_Two_Varibales_Without_Temporary_Variable.c
 Author      : Hassan_Attia
 Version     :
 Copyright   : 
 Description : a program to swap two variables without using a temporary variable
 ==================================================================================
 */

#include <stdio.h>



int main(){

    float x=0,y=0;

	printf("Enter an value of a:\n");

	fflush(stdin);fflush(stdout);

	scanf("%f",&x);

	printf("Enter an value of b:\n");

		fflush(stdin);fflush(stdout);

		scanf("%f",&y);

     x=x+y;
     y=x-y;
     x=x-y;

       printf("After Swapping,value of a: %0.2f \n",x);

       fflush(stdout);

       printf("After Swapping,value of b: %0.2f \n",y);

}

