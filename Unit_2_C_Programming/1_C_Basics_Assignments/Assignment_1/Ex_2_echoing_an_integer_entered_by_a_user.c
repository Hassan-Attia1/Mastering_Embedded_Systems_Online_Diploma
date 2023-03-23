/*
 ============================================================================
 Name        : Ex_2_echoing_an_integer_entered_by_a_user.c
 Author      : Hassan_Attia
 Description : a program to print an integer entered by user
 ============================================================================
 */

#include <stdio.h>



int main(){

    int x=0;

	printf("Enter an integer:\n");

	fflush(stdin);fflush(stdout);

	scanf("%d",&x);

	printf("You entered: %d",x);
}

