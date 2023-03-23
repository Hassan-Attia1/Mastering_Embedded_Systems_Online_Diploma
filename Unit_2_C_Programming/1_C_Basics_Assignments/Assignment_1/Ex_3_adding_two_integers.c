/*
 ============================================================================
 Name        : Ex_3_adding_two_integers.c
 Author      : Hassan_Attia
 Description : a program to add two integers
 ============================================================================
 */

#include <stdio.h>



int main(){

    int x=0,y=0;

	printf("Enter two integers:\n");

	fflush(stdin);fflush(stdout);

	scanf("%d %d",&x,&y);

	printf("Sum: %d",x+y);
}

