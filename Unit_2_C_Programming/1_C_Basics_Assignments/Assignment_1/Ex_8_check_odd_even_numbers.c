/*
 ============================================================================
 Name        : assignment_1_Ex_8_check_odd_even_numbers.c
 Author      : Hassan_Attia
 Description : program to check the weather the number is even or odd
 ============================================================================
 */

#include<stdio.h>

int main(){

	int num=0;

	printf("Enter an integer : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	if(num%2==0){

		printf("%d is even",num);
	}

	else{

		printf("%d is odd",num);
	}

	return 0;


}
