/*
 ============================================================================
 Name        : assignment_5_Ex_4_reverse_array_elements_using_pointers.c
 Author      : Hassan_Attia
 Description : a c program to print array elements in reverse
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	int arr[20];
	int* pt_arr = arr;
	int size, i;

	printf("please enter array size:\n");
	fflush(stdout); fflush(stdin);
	scanf("%d", &size);



	for(i=0; i<size; i++){


		printf("element [%d]:",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d",pt_arr + i);

	}


	printf("\n\r");
printf("array you've entered is :\n");

	for(i=0; i<size; i++)
	{


		printf("element [%d] is %d\n",i+1,*pt_arr);
		fflush(stdout);
		if(i!=size-1)
		pt_arr++;

	}





printf("\n\rReversing array...\n\r");


for(i=size; i>0; i--){


	printf("element [%d] is %d\n",i, *pt_arr);
    pt_arr--;

}



	return 0;
}
