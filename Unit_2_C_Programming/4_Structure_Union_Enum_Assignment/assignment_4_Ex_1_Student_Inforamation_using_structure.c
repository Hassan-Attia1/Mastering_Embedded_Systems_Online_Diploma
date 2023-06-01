/*
 ==================================================================================
 Name        : assignment_4_Ex_1_Student_Inforamation_using_structure.c
 Author      : Hassan_Attia
 Description : A program to display student information using structure date type
 ==================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SStudent_info{

	char m_name[50];//student name
	int m_roll_no;//student roll number
	float m_grade;//student grade



};


int main(void) {



	struct SStudent_info student;

	printf("Please Enter Student Name:\n");
	fflush(stdout); fflush(stdin);
	scanf("%s",student.m_name);

	printf("Enter Student Roll Number:\n");
	fflush(stdout); fflush(stdin);
	scanf("%d", &student.m_roll_no);

	printf("Enter Student Mark\n");
	fflush(stdout); fflush(stdin);
	scanf("%f", &student.m_grade);


	printf("Name: %s\n",student.m_name);
	fflush(stdout);
	printf("Roll Number is: %d\n",student.m_roll_no);
	fflush(stdout);
	printf("Marks: %0.1f",student.m_grade);





	return 0;


}
