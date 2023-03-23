/*
 ============================================================================
 Name        : assignment_1_Ex_13_sum_of_natural_numbers.c
 Author      : Hassan_Attia
 Description : program prints sum of natural numbers
 ============================================================================
 */


#include<stdio.h>

int main(){


	int sum=0,i=0,num=0;

	printf("Please Enter an Integer: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	for(i=1;i<=num;i++){\


		sum+=i;


	}


	printf("sum= %d",sum);



}
