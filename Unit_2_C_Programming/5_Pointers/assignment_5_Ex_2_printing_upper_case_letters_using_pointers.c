/*
 ============================================================================
 Name        : assignment_5_Ex_2_printing_upper_case_letters_using_pointers.c
 Author      : Hassan_Attia
 Description : a c program to print english letters using pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

 int i;
 char alpha ='A';

 char* pt_alpha = &alpha;

	for(i=0 ; i<26	; i++){

		printf("%c ", *pt_alpha);
		*pt_alpha+=1;

	}

	return 0;

}
