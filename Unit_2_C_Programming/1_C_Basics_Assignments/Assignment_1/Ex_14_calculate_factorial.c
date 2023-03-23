/*
 ============================================================================
 Name        : assignment_1_Ex_14_calculate_factorial.c
 Author      : Hassan_Attia
 Description : program to calculate the factorial for a number
 ============================================================================
 */

#include<stdio.h>

int main(){


	int num= 0,fact=1,i=0;

    printf("Please Enter a number: \n");
    fflush(stdin); fflush(stdout);
    scanf("%d",&num);

    if(num<0)
    	printf("Error,Enter only a positive number");
    else if(num==0)
        printf("the factorial of (%d!) is: %d	",num,num+1);
    else{

    	for(i=2;i<=num;i++){


    		fact*=i;

    	}

    	printf("the factorial of (%d!) is: %d",num,fact);
    }






	return 0;
}
