/*
 ============================================================================
 Name        : assignment_2_strings_Ex_3_reverse_string.c
 Author      : Hassan_Attia
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {

	int i=0,counter=0;
	char string[60],rev_string[60];

	printf("Enter a string: \r\n");
	fflush(stdin); fflush(stdout);
	gets(string);
	counter=strlen(string);
	for(i=0;i<strlen(string);i++){

		rev_string[i]=string[counter-1];
		counter-=1;;


	}

	rev_string[i]='\0';

	printf("String after reverse:\r\n");

	printf("%s",rev_string);

	return 0;
}
