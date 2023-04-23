/*
 ============================================================================================================
 Name        : assignment_3_Ex_1_prime_numbers.c
 Author      : Hassan_Attia
 Description : a program to find prime numbers between two intervals by using function
 ============================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void prime_detector(int first_interval,int second_interval);

int main( ) {

    int interval_1,interval_2;

    printf("Please enter 2 Intervals: \n");

    fflush(stdout); fflush(stdin);

    scanf("%d %d",&interval_1,&interval_2);

	prime_detector(interval_1,interval_2);


	return 0;



}


void prime_detector(int first_interval,int second_interval){

	if(first_interval==1){
		first_interval++;
		printf("prime numbers between %d and %d are: \n\r ",first_interval-1,second_interval);
	}

	else
		printf("prime numbers between %d and %d are: \n\r ",first_interval,second_interval);

	int i,j;


	for(i=first_interval;i<=second_interval;i++){

		for(j=2;j<i;j++){
			if(i%j==0){
				break;
			}


		}

		if(j==i){

			printf("%d ",i);

		}

	}


}
