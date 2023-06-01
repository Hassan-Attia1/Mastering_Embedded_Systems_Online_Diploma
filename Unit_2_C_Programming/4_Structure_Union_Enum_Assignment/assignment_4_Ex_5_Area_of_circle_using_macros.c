/*
 ========================================================================================
 Name        : assignment_4_Ex_5_Area_of_circle_using_macros.c
 Author      : Hassan_Attia
 Description : a c program to find area of circle using macros pre-processing directive
 ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define area(rad) ((22.0/7)*rad*rad)

int main(void) {

	float radius;

	printf("please enter the circle radius:\n");
	fflush(stdout); fflush(stdin);
	scanf("%f", &radius);

	printf("area = %0.2f",area(radius));








	return 0;
}
