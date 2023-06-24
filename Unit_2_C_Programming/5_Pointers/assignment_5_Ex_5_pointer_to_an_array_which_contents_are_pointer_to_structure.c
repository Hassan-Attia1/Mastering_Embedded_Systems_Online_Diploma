/*
 =================================================================================================================
 Name        : assignment_5_Ex_5_pointer_to_an_array_which_contents_are_pointer_to_structure.c
 Author      : Hassan_Attia
 Description : a c program illustrates how to make pointer to an array which contents are pointer to structure
 =================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct Semployee{

	char m_name[30];
	int m_id;


};

int main() {

int i;
	struct Semployee emps[]={ {"khaild",1}, {"Ali",5}, {"Omar",9} };

	struct Semployee* pt_emps = emps;

	for(i=0;i<3;i++){



	printf("Employee name: %s\n\rEmployee Id:%d\r\n", (pt_emps+i)->m_name, (pt_emps+i)->m_id);

	}


	return 0;
}
