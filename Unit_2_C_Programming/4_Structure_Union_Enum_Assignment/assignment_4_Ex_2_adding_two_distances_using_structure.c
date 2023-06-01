/*
 =====================================================================================
 Name        : assignment_4_Ex_2_adding_two_distances_using_structure.c
 Author      : Hassan_Attia
 Description : c program to add two distances in {inch-feet} system using structure
 =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SINCH_FEET{

	int m_feet;
	float m_inch;

};



int main(void)

{

	struct SINCH_FEET variable[2],sum;
	int i;

	for(i=0;i<2;i++){

		printf("Enter %dst\n",i+1);
		fflush(stdout);

		printf("Enter Feet Distance:\n");
		fflush(stdout); fflush(stdin);
		scanf("%d", &variable[i].m_feet);

		printf("Enter Inch Distance:\n");
		fflush(stdin); fflush(stdout);
		scanf("%f", &variable[i].m_inch);

		printf("\n");


	}


	sum.m_feet = variable[0].m_feet + variable[1].m_feet;
	sum.m_inch = variable[0].m_inch + variable[1].m_inch;

	while(1){

		if(sum.m_inch>=12){

			sum.m_inch -= 12;
			sum.m_feet++;

		}

		else
			break;

	}


	printf("Total Distance is %d' feet and %.1f'' inches\n",sum.m_feet, sum.m_inch);




	return 0;
}
