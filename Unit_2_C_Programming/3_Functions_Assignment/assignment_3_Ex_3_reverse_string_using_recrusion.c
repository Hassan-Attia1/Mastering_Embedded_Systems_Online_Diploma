/*
 ============================================================================
 Name        : assignment_3_Ex_3_reverse_string_using_recrusion.c
 Author      : Hassan_Attia
 Description : a program can use a recursion function to reverse a string
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 void Reverse();

int main( )
{

    printf("Enter a sentence: \n ");
    fflush(stdout); fflush(stdin);
    Reverse();

    return 0;


}

void Reverse(){

	char c;
	scanf("%c",&c);
	if(c!= '\n')
	{
		Reverse();
		printf("%c",c);
	}



}
