/*
 =========================================================================================
 Name        : assignment_2_strings_Ex_2_string_length.c
 Author      : Hassan_Attia
 Description : a program can calculate length of string without using strlen() function
 =========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	int i,counter=0;
	char string[40];

	printf("Enter a string: \n");
	fflush(stdout); fflush(stdin);
	gets(string);

	for(i=0;string[i]!='\0';i++){


		counter+=1;
	}

	printf("Length of string is: %d",counter);



	return 0;



}
