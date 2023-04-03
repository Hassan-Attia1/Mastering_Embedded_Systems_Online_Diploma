/*
 ===================================================================================
 Name        : assignment_2_strings_Ex_1_frequency_of_character_in_string.c
 Author      : Hassan_Attia
 Description : a program can calculate how many character has repeated in a string
 ===================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {


	char string[100];

	char findchar='\0';

	int repeat=0,counter=0;
	int i;

	printf("Enter a string \n");
	fflush(stdin); fflush(stdout);
	gets(string);


	printf("enter a character to find how many times that character repeated: \n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&findchar);


	counter=strlen(string);

	for(i=0;i<counter;i++){

		if(string[i]==findchar){

			repeat+=1;


		}


	}


	printf("the character %c has been repeated %d times.",findchar,repeat);





	return 0;

}
