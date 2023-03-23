/*
 ==============================================================================================
 Name        : assignment_1_Ex_12_check_character.c
 Author      : Hassan_Attia
 Description : program to check weather the character entered by user is alphabet or not
 ==============================================================================================
 */

#include<stdio.h>

int main(){
	int i= 0,j= 0;

	char x='\0';

	printf("Enter a character: \n");

	fflush(stdin); fflush(stdout);

	scanf("%c",&x);

	for(i=65;i<=90;i++){

		if(x==i){

			printf("%c is alphabet",x);

             break;

		}
           continue;

	}


	for(j=97;j<=122;j++){

		if(x==j){

			printf("%c is alphabet",x);
			break;
		}
		continue;

	}


	  if(i>90&&j>122){
		  printf("%c in not alphabet",x);

	  }

	return 0;
}
