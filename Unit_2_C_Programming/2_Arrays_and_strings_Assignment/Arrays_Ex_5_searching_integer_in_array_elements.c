/*
 ==============================================================================
 Name        : assignment_2_Arrays_Ex_5_searching_integer_in_array_elements.c
 Author      : Hassan_Attia
 Description : a program can find an integer entered by user in array elements
 ==============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	int i,e,num,location;

	int arr[20];



	printf("Enter number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&e);

	for(i=0;i<e;i++){


		scanf("%d",&arr[i]);


	}

	printf("\r\n");

	findagain:
	/* if the integer is not founded in the array
	   this label will allow the user to enter a number again
	 */
	printf("Enter the integer that you want to find: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);


	for(i=0;i<e;i++){


		if(arr[i]==num){

			location=i+1;
			break;
		}




	}


	if(i==e){

		printf("sorry,number not found in array elements,try again \r\n");

		goto findagain;
	}



	printf("integer found at location: %d",location);








	return 0;

}
