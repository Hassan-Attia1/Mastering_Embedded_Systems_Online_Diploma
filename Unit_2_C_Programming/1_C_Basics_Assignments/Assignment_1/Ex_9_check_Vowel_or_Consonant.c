/*
 ============================================================================
 Name        : assignment_1_Ex_9_check_Vowel_or_Consonant.c
 Author      : Hassan_Attia
 Description : program to check weather the letter is consonant or vowel
 ============================================================================
 */

#include<stdio.h>


int main(){


	char letter='\0';


	printf("Enter a letter: \n");

	fflush(stdin); fflush(stdout);

	scanf("%c",&letter);


	switch(letter){


	case 'a':
	case 'A':
	{
		printf("%c is a vowel letter",letter);
	}


	break;

	case 'e':
	case 'E':
	{

		printf("%c is a vowel letter",letter);
	}

	break;

	case 'o':
	case 'O':
	{

		printf("%c is a vowel letter",letter);

	}

	break;


	case 'i':
	case 'I':
	{

		printf("%c is a vowel letter",letter);
	}

	break;

	case 'u':
	case 'U':

	{
		printf("%c is a vowel letter",letter);
	}
	break;

	default:{

		printf("%c is a consonant letter",letter);
	}
	break;
	}
}
