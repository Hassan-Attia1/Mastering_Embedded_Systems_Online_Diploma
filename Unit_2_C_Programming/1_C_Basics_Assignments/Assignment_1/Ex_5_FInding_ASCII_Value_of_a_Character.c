/*
 ============================================================================
 Name        : Ex_5_FInding_ASCII_Value_of_a_Character.c
 Author      : Hassan_Attia
 Version     :
 Copyright   : 
 Description : a program to find the ASCII value of a character
 ============================================================================
 */

#include <stdio.h>



int main(){

    char x='\0';

	printf("Enter a charcter:\n");

	fflush(stdin);fflush(stdout);

	scanf("%c",&x);

	printf("ASCII value of %c is: %d",x,x);
}

