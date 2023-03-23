/*
 ============================================================================
 Name        : assignment_1_Ex_10_Largest_number.c
 Author      : Hassan_Attia
 Description : program to find largest number among three numbers
 ============================================================================
 */

#include<stdio.h>


int main(){


	float a= 0.0,b= 0.0,c= 0.0;

	printf("enter three numbers: \n");

	fflush(stdin); fflush(stdout);

	scanf("%f %f %f",&a,&b,&c);

	if(a>b){

		if(a>c){

			printf("Largest number is: %f \n",a);


		}

		else{
			printf("Largest number is: %f  \n",c);

		}

	}

	else{
		if(b>c){

			printf("Largest number is: %f ",b);

		}

		else{

			printf("Largest number is: %f ",c);
		}

	}




	return 0;

}
