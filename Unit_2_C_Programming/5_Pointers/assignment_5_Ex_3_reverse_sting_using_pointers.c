/*
 ============================================================================
 Name        : assignment_5_Ex_3_reverse_sting_using_pointers.c
 Author      : Hassan_Attia
 Description : a c program to print string in reverse using pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i,char_counter = 0;
	char string[30];
	char* pt_string = string;


	printf("enter string\n\r");
	fflush(stdout); fflush(stdin);
	gets(string);



	while(1){
		if( *pt_string != '\0' ){

			pt_string++;
			char_counter++;
		}

		else
			break;
	}

printf("string after reversing is:\n\r");

	for(i=0; i<=char_counter ; i++){

		printf("%c",*pt_string);
		pt_string--;


	}






}
