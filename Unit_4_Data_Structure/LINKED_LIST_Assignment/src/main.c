/*
 =====================================================================================================
 Name        : LINKED_LIST_Assignment.c
 Author      : Hassan_Attia
 Description : a C program uses linked list data structure to create student data base
 =====================================================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stddef.h>

//Student Info

typedef struct{
	unsigned char NAME[50];
	unsigned int ID;
	float HEIGHT;


}S_INFO;

typedef struct{

	S_INFO student_info;
	S_INFO* p_next_student;

}STUDENT_INFO;

//pointer to point on the first link or node

STUDENT_INFO* gp_first_student = NULL;

//Data base functions
void ADD_S();// Add a student
int DEL_S();// Delete a student
void VIEW_S();// View all students
void DEL_ALL();//Delete All students
void fill_student(STUDENT_INFO* new_student);//Fill student data

//Adding some features
void GetNth(STUDENT_INFO* head,unsigned int index );//a function to get Nth node in a linked list
void Length_Ittirative(STUDENT_INFO* head);//measure a linked list Length
void GetNth_From_End(STUDENT_INFO* head,unsigned int Index );//a function to get Nth node in a linked list but, you're starting from last element
void Get_Middle(STUDENT_INFO* head);// obtaining the middle node (Even or Odd)
int  reverse_linked_list(STUDENT_INFO* head);//Reverse a linked list


int main(void) {




	char temp[50];
	while(1){
		printf("\n******************WELCOME TO STUDENT DATA BASE********************\n");
		fflush(stdout);

		printf("\nPlease Select One of The Following options:\n");
		fflush(stdout);

		printf("\n1:Add a Student\n");
		fflush(stdout);

		printf("\n2:Delete a Student\n");
		fflush(stdout);

		printf("\n3:View Students\n");
		fflush(stdout);

		printf("\n4:Delete All Students\n");
		fflush(stdout);

		printf("\n5:Find a student by index\n");
		fflush(stdout);

		printf("\n6:Find a linked list length\n");
		fflush(stdout);

		printf("\n7:Find a student by index but in reverse\n");
		fflush(stdout);

		printf("\n8:Find Middle student in given data base\n");
		fflush(stdout);

		printf("\n9:Reverse the list\n");
		fflush(stdout);


		printf("\n******************************************************************\n");
		fflush(stdout);

		gets(temp);

		switch(atoi(temp)){



		case 1:
			ADD_S();
			break;

		case 2:
			DEL_S();
			break;
		case 3:
			VIEW_S();
			break;
		case 4:
			DEL_ALL();
			break;
		case 5:
			if(gp_first_student == NULL){
				printf("\n List is empty\n");
			}
			else{
				printf("\nEnter index number:\n");
				fflush(stdout); fflush(stdin);
				gets(temp);
				GetNth(gp_first_student,atoi(temp));}
			break;
		case 6:
			if(gp_first_student == NULL){
				printf("\n List is empty\n");
			}
			else{
				Length_Ittirative(gp_first_student);
			}
			break;

		case 7:
			if(gp_first_student == NULL){
				printf("\n List is empty\n");
			}
			else{
				printf("\nEnter index number:\n");
				fflush(stdout); fflush(stdin);
				gets(temp);
				GetNth_From_End(gp_first_student,atoi(temp));}
			break;

		case 8:
			if(gp_first_student == NULL){
				printf("\n List is empty\n");
			}
			else{
				Get_Middle(gp_first_student);
			}
			break;

		case 9:
			if(gp_first_student == NULL){
				printf("\n List is empty\n");
			}
			else{
				reverse_linked_list(gp_first_student);
			}
			break;

		default:
			printf("\nWrong Option...\n");
			fflush(stdout);
			break;

		}




	}





	return 0;
}



//Adding a student
void ADD_S(){
	STUDENT_INFO* p_new_student;
	STUDENT_INFO* p_last_student;

	//checking on list if it's empty
	if(gp_first_student == NULL){

		//create first student
		p_new_student = (STUDENT_INFO*)malloc(sizeof(STUDENT_INFO));
		//assign head pointer to the first student
		gp_first_student = p_new_student;
		//new student pointer will point on NULL


	}
	//if the list isn't empty
	else{
		p_last_student = gp_first_student;
		//navigate till you find the last student i.e NULL
		while(p_last_student->p_next_student){

			p_last_student = p_last_student->p_next_student;

		}

		//CREATE A NEW STUDENT
		p_new_student = (STUDENT_INFO*)malloc(sizeof(STUDENT_INFO));
		p_last_student->p_next_student = p_new_student;


	}

	fill_student(p_new_student);

	p_new_student->p_next_student =NULL;




}


//fill student information
void fill_student(STUDENT_INFO* new_student){
	char temp_name[50];

	printf("\nEnter the name :\n");
	fflush(stdout);
	gets(new_student->student_info.NAME);

	printf("\nEnter Student ID\n");
	fflush(stdout);

	gets(temp_name);
	new_student->student_info.ID = atoi(temp_name);


	printf("\nEnter Student Height:\n");
	fflush(stdout);
	gets(temp_name);
	new_student->student_info.HEIGHT = atof(temp_name);
}

//Deleting a student
int DEL_S(){
	char temp_text[30];
	int id;
	printf("\nEnter student ID to delete his/her data\n");
	fflush(stdout);
	gets(temp_text);
	id = atoi(temp_text);

	if(gp_first_student){

		STUDENT_INFO* p_previous_student = NULL;
		STUDENT_INFO* p_selected_student = gp_first_student;
		//loop on all records starting from the first link or elements
		while(p_selected_student){


			if(p_selected_student->student_info.ID ==id){

				if(p_previous_student){

					p_previous_student->p_next_student= p_selected_student->p_next_student;


				}

				else{

					gp_first_student = p_selected_student->p_next_student;


				}
				//remove selected id
				free(p_selected_student);
				return 1;

			}
			//store the previous record to keep searching on the selected id
			p_previous_student = p_selected_student;
			p_selected_student = p_selected_student->p_next_student;

		}

	}



	printf("\ncan't find the ID that you've entered\n");
	return 0;




}

//viewing all students
void VIEW_S(){
	unsigned int student_num =0;
	//Selected student
	STUDENT_INFO* v_student = gp_first_student;

	if(gp_first_student == NULL)
		printf("\nEmpty List\n");

	while(v_student){
		printf("\nStudent number [%d]\n",student_num+1);
		fflush(stdout);
		printf("\nName:%s\n",v_student->student_info.NAME);
		fflush(stdout);
		printf("\nID:%d\n",v_student->student_info.ID);
		fflush(stdout);
		printf("\nHeight:%f\n",v_student->student_info.HEIGHT);
		fflush(stdout);

		v_student = v_student->p_next_student;
		student_num++;

	}





}

//Deleting all students
void DEL_ALL(){

	STUDENT_INFO* p_current_student = gp_first_student;

	//check if the list is empty
	if(gp_first_student == NULL)
		printf("\nEmpty List\n");

	else{
		//loop on all elements
		while(p_current_student){
			//create a temporary struct to point on the current & then make the current struct point on the next element
			STUDENT_INFO* p_temp_removal = p_current_student;
			p_current_student = p_current_student->p_next_student;
			free(p_temp_removal);

		}

		gp_first_student = NULL;
		printf("\nAll Students Deleted...\n");


	}

}




void GetNth(STUDENT_INFO* head,unsigned int Index ){


	//check if the list is empty
	if(gp_first_student == NULL)
		printf("\nList is empty\n");
	else{

		STUDENT_INFO* p_last_student = gp_first_student;
		unsigned int count  = 0;
		while(count != Index){

			count++;
			p_last_student = p_last_student->p_next_student;

		}



		printf("\nName:%s\n",p_last_student->student_info.NAME);
		fflush(stdout);
		printf("\nID:%d\n",p_last_student->student_info.ID);
		fflush(stdout);
		printf("\nHeight:%f\n",p_last_student->student_info.HEIGHT);
		fflush(stdout);


	}



}




void Length_Ittirative(STUDENT_INFO* head){
	unsigned int count  = 1;
	//check if the list is empty
	if(gp_first_student == NULL)
		printf("\nList is empty\n");

	else{

		STUDENT_INFO* p_last_student = gp_first_student;

		while(p_last_student->p_next_student){
			p_last_student = p_last_student->p_next_student;
			count++;


		}

	}

	printf("\nLength of the linked list = %d\n",count);
	fflush(stdout);

}



void GetNth_From_End(STUDENT_INFO* head,unsigned int Index ){

	STUDENT_INFO* p_target_sudent = gp_first_student;
	STUDENT_INFO* p_node_length = gp_first_student;
	unsigned int list_length  = 0;
	//check if the list is empty
	if(gp_first_student == NULL)
		printf("\nList is empty\n");
	else{


		while(p_node_length->p_next_student){
			p_node_length = p_node_length->p_next_student;
			list_length++;
		}


		while(list_length != Index ){

			p_target_sudent = p_target_sudent->p_next_student;
			list_length--;


		}

		printf("\nName:%s\n",p_target_sudent->student_info.NAME);
		fflush(stdout);
		printf("\nID:%d\n",p_target_sudent->student_info.ID);
		fflush(stdout);
		printf("\nHeight:%f\n",p_target_sudent->student_info.HEIGHT);
		fflush(stdout);



	}



}


void Get_Middle(STUDENT_INFO* head){
	STUDENT_INFO* p_slow = gp_first_student;
	STUDENT_INFO* p_speed = gp_first_student;

	if(gp_first_student == NULL){
		printf("\nList is empty\n");
		return;}
	else{

		while( (p_slow->p_next_student) && (p_speed ->p_next_student)){

			p_slow = p_slow->p_next_student;

			p_speed = p_speed->p_next_student;
			//This check for even nodes to ensure that the speed pointer will not point on unaccessible data which will lead to segmentation fault
			if(p_speed->p_next_student == NULL)
				break;

			p_speed = p_speed->p_next_student;

		}

		printf("\nName:%s\n",p_slow->student_info.NAME);
		fflush(stdout);
		printf("\nID:%d\n",p_slow->student_info.ID);
		fflush(stdout);
		printf("\nHeight:%f\n",p_slow->student_info.HEIGHT);
		fflush(stdout);




	}




}



int reverse_linked_list(STUDENT_INFO* head){



	if(gp_first_student == NULL){
		printf("\n Empty list\n");
		return 0;}

	STUDENT_INFO* p_current = gp_first_student;
	STUDENT_INFO* p_previous = NULL;
	STUDENT_INFO* p_next = NULL;

	while(p_current != NULL){

		p_next = p_current->p_next_student;
		p_current->p_next_student = p_previous;
		p_previous = p_current;
		p_current = p_next ;


	}

	//make the head pointer point on the last item
	gp_first_student = p_previous;
	return 1;


}


