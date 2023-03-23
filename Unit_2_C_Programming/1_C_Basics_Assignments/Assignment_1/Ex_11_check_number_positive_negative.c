/*
 ============================================================================
 Name        : assignment_1_Ex_11_check_number_positive_negative.c
 Author      : Hassan_Attia
 Description :program to check weather the number is positive or negative
 ============================================================================
 */

#include<stdio.h>

int main(){


	float num=0;


	printf("please enter a number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num);

	if(num>=0){

		printf("%0.2f is a positive number",num);
	}

	else
		printf("%0.2f is a negative number",num);




}
