/*
 ============================================================================
 Name        : assignment_2_Arrays_Ex_3_Transposing_matrix_all_sizes.c
 Author      : Hassan_Attia
 Description : program to transpose any matrix size
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	int i,j,rows,columns;
	int matA[50][50];
	int matB[50][50];

	printf("Enter number of rows: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&rows);


	printf("Enter number of columns: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&columns);

	for(;(rows<=0 || rows>50 || columns<=0 || columns>50);){

		printf("Error!,number of rows or columns is out of range, please use the range (1-50) \r\n");

		printf("Enter number of rows: \n");
		fflush(stdin); fflush(stdout);
		scanf("%d",&rows);


		printf("Enter number of columns: \n");
		fflush(stdin); fflush(stdout);
		scanf("%d",&columns);

	}


	if(rows==columns){



		for(i=0;i<rows;i++){



			for(j=0;j<columns;j++){

				printf("Element number [%d][%d]: \n",i+1,j+1);
				fflush(stdin); fflush(stdout);
				scanf("%d",&matA[i][j]);

			}




		}


		for(i=0;i<rows;i++){



			for(j=0;j<columns;j++){

				if(i==j){

					matB[i][j]=matA[i][j];


				}

				else{

					matB[i][j]=matA[j][i];

				}




			}




		}


		printf("The old matrix: \n");

		for(i=0;i<rows;i++){

			for(j=0;j<columns;j++){

				printf("%d ",matA[i][j]);


			}

			printf("\n");




		}





		printf("The new matrix after transpose: \n");

		for(i=0;i<rows;i++){

			for(j=0;j<columns;j++){

				printf("%d ",matB[i][j]);


			}

			printf("\n");




		}





	}







	else if(rows<columns){

		for(i=0;i<rows;i++){

			for(j=0;j<columns;j++){

				printf("Element number [%d][%d]: \n",i+1,j+1);
				fflush(stdin); fflush(stdout);
				scanf("%d",&matA[i][j]);

			}


		}



		for(i=0;i<rows;i++){

			for(j=0;j<columns;j++){


				matB[j][i]=matA[i][j];

			}


		}

		printf("The old matrix: \n");

		for(i=0;i<rows;i++){

			for(j=0;j<columns;j++){


				printf("%d ",matA[i][j]);

			}

			printf("\n");

		}



		printf("The new matrix: \n");

		for(i=0;i<columns;i++){

			for(j=0;j<rows;j++){


				printf("%d ",matB[i][j]);

			}

			printf("\n");

		}



	}



	else{



		for(i=0;i<rows;i++){



			for(j=0;j<columns;j++){

				printf("Element number [%d][%d]: \n",i+1,j+1);
				fflush(stdin); fflush(stdout);
				scanf("%d",&matA[i][j]);

			}




		}



		for(i=0;i<columns;i++){

			for(j=0;j<rows;j++){


				matB[i][j]=matA[j][i];

			}


		}





		printf("The old matrix: \n");

		for(i=0;i<rows;i++){

			for(j=0;j<columns;j++){


				printf("%d ",matA[i][j]);

			}

			printf("\n");

		}



		printf("The new matrix: \n");

				for(i=0;i<columns;i++){

					for(j=0;j<rows;j++){


						printf("%d ",matB[i][j]);

					}

					printf("\n");

				}





	}







	return 0;

}
