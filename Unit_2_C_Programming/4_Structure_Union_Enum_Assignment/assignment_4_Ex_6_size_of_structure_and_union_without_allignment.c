/*
 ============================================================================
 Name        : assignment_4_Ex_6_size_of_structure_and_union_without_allignment.c
 Author      : Hassan_Attia
 Description : size of structure and union without padding
 ============================================================================
 */

#include<stdio.h>
#include<string.h>
#include<conio.h>

union job {
	char name[32];
	float salary;
	int worker_no;
}u;

struct job1 {
	char name[32];
	float salary;
	int worker_no;
}s;


int main()
{
printf("%d\n",sizeof(u));
printf("%d",sizeof(s));
	return 0;
}

// the output will be
// 32
// 40
// because the compiler works with Packing method
