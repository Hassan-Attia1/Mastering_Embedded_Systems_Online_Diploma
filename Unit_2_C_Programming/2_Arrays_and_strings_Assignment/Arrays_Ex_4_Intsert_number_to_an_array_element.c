/*
 ============================================================================
 Name        : assignment_2_Arrays_Ex_4_Intsert_number_to_an_array_element.c
 Author      : Hassan_Attia
 Description : a program to insert a number in a specific array element
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	int i,e,num,location;
	int arr[20];

	printf("Enter number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&e);

	for(i=0;i<e;i++){


		scanf("%d",&arr[i]);


	}

	printf("\r\n");

 printf("Enter the integer to be inserted: \n");
 fflush(stdin); fflush(stdout);
 scanf("%d",&num);

 printf("which element in the array to be replaced ? \n");
  fflush(stdin); fflush(stdout);
  scanf("%d",&location);

  arr[location-1]=num;



	for(i=0;i<e;i++){


		printf("%d ",arr[i]);


	}





	return 0;
}
