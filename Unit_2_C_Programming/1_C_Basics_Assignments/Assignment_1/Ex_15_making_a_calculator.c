/*
 ============================================================================
 Name        : assignment_1_Ex_15_making_a_calculator.c
 Author      : Hassan_Attia
 Description : program of a simple calculator
 ============================================================================
 */

#include<stdio.h>

int main(){

	float a=0,b=0;

	char op='\0';

	printf("enter the operation you want to make + or - or * or / : \n");

	fflush(stdin); fflush(stdout);

	scanf("%c",&op);


	printf("enter two numbers only: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&a,&b);


	switch(op){


	case '+':

		printf("%.2f + %.2f = %.2f",a,b,a+b);

		break;

	case '-':

			printf("%.2f - %.2f = %.2f",a,b,a-b);

			break;

	case '*':

			printf("%.2f*%.2f = %.2f",a,b,a*b);

			break;


	case '/':

			printf("%.2f/%.2f = %.2f",a,b,a/b);

			break;

	default:
		printf("Error!!,please enter the correct sign \n");
		break;


	}










	return 0;
}
