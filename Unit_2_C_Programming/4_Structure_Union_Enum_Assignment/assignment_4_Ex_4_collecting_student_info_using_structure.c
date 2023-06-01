/*
 =======================================================================================
 Name        : assignment_4_Ex_4_collecting_student_info_using_structure.c
 Author      : Hassan_Attia
 Description : a c program to store student information using structure data type
 =======================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SStudent{

	char m_name[40];
	int m_roll;
	float m_marks;


};


int main(void) {


	struct SStudent student[10];
	int i, count = 0;

	do{

		printf("Enter student %d name\n",count+1);
		fflush(stdout); fflush(stdin);
		scanf("%s",student[count].m_name);

		printf("Enter roll number:\n");
		fflush(stdout); fflush(stdin);
		scanf("%d", &student[count].m_roll);

		printf("Enter Marks:\n");
		fflush(stdout);  fflush(stdin);
		scanf("%f", &student[count].m_marks);

		count++;




	}
	while(count<10);


	printf("the data you.ve stored is:\n");

	for(i=0;i<count;i++){
		printf("Roll number:%d\n", student[i].m_roll);
		fflush(stdout);
		printf("Name:%s\n",student[i].m_name);
		fflush(stdout);
		printf("Marks:%.1f\n", student[i].m_marks);




	}






	return 0;



}
