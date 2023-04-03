/*
 ============================================================================
 Name        : assignment_2_Arrays_Ex_1_sum_of_two_matrix.c
 Author      : Hassan_Attia
 Description : a program can make the sum of two matrices of order 2x2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

float mat1[2][2];
float mat2[2][2];
float mat3[2][2];
int i,j;

printf("First,Enter the elements of the first matrix: \n");


for(i=0;i<2;i++){


	for(j=0;j<2;j++){

		printf("Enter the element a[%d][%d]: \n",i+1,j+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&mat1[i][j]);



	}



}



printf("Second,Enter the elements of the second matrix: \n");

for(i=0;i<2;i++){


	for(j=0;j<2;j++){

		printf("Enter the element a[%d][%d]: \n",i+1,j+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&mat2[i][j]);



	}



}




for(i=0;i<2;i++){


	for(j=0;j<2;j++){


		mat3[i][j]=mat1[i][j]+mat2[i][j];



	}



}


printf("The Sum of Two matrices is: \n");


for(i=0;i<2;i++){


	for(j=0;j<2;j++){

		printf("%0.2f ",mat3[i][j]);


	}

	printf("\n");

}


	return 0;


}
