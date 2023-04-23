/*
 ============================================================================
 Name        : assignment_3_Ex_4_power_of_a_number_using_recrusion.c
 Author      : Hassan_Attia
 Description : a program to get power of a number by using recursion function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int power1(int base,int pow);


int main(void) {

	int base,power,result;
	printf("Please enter the base:\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&base);

	printf("Please enter the power:\n");
	fflush(stdout); fflush(stdin);
	scanf("%d",&power);

    result=power1(base,power);
	printf("%d^%d= %d",base,power,result);


return 0;

}



int power1(int base,int pow){

	int result=base;

	if(pow==1){

		return result;
	}

	pow--;

	return result*power1(result,pow);


}
