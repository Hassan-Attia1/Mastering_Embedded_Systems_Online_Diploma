/*
 ============================================================================
 Name        : assignment_2_Arrays_Ex_2_Calculating_the_Average_using_Arrays.c
 Author      : Hassan_Attia
 Description : a program to calculate the average by using arrays
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i,elements;

	float arr_num[50];

	float average=0,sum=0;

	printf("How many numbers do want to enter to get the average? \n");
	fflush(stdout); fflush(stdin);
	scanf("%d",&elements);

	for(;elements<=0 || elements>50;){


	printf("Error!! Wrong number entered, please enter a number within range (1-50) \n");

	printf("How many numbers do want to enter to get the average? \n");
		fflush(stdout); fflush(stdin);
		scanf("%d",&elements);




	}


	for(i=0;i<elements;i++){

		printf("%d.Enter a number: \n",i+1);

		fflush(stdin); fflush(stdout);

		scanf("%f",&arr_num[i]);



	}


	for(i=0;i<elements;i++){


		sum+=arr_num[i];

	}


	average=sum/(i);


	printf("The average is : %.2f",average);



}
