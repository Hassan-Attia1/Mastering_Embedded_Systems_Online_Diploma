/*
 ============================================================================
 Name        : Ex_4_Multiplying_Two_Floating_Numbers.c
 Author      : Hassan_Attia
 Description : a program to multiply two floating numbers
 ============================================================================
 */

#include <stdio.h>



int main(){

    float x=0,y=0;

	printf("Enter two numbers:\n");

	fflush(stdin);fflush(stdout);

	scanf("%f %f",&x,&y);

	printf("Product= %f",x*y);
}

