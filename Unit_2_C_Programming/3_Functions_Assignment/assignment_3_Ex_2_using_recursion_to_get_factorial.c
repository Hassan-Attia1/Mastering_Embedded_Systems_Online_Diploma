/*
 ============================================================================
 Name        : assignment_3_Ex_2_using_recursion_to_get_factorial.c
 Author      : Hassan_Attia
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int fact(int number);

int main( ) {


int number,result;

restart:
printf("please enter positive integer : \n");
fflush(stdout); fflush(stdin);
scanf("%d",&number);

if (number<0){

	printf("you've entered a negative integer !! : \n");
	printf("please make sure integer is positive \n\r");
	goto restart;


}



result=fact(number);

printf("the factorial of %d is : %d",number,result);

	return 0;
}


int fact(int number){

	int factorial=1;

	if(number==0||number==1){
		return 1;
	}

		factorial*=number;
		number--;

	   return factorial*fact(number);











return 0;


}
