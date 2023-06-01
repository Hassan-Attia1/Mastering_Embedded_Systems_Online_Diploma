/*
 ============================================================================
 Name        : assignment_4_Ex_3_adding_two_Complex_Numbers_using_structure.c
 Author      : Hassan_Attia
 Description : A c program adds two complex number using structure
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SComplex{

	double m_real;//complex number Real part
	double m_img;//complex number Imaginary part



};


struct SComplex Read_complex(char str[])
{

	struct SComplex complex;

	printf("%s  ex:5 -3\n", str);
	fflush(stdout); fflush(stdin);
	scanf("%lf %lf", &complex.m_real, &complex.m_img);

	return complex;

}

struct SComplex add_complex(struct SComplex complex1,struct SComplex complex2)
{
	struct SComplex SUM;

	SUM.m_real = complex1.m_real + complex2.m_real;
	SUM.m_img = complex1.m_img + complex2.m_img;

	return SUM;




}


void print_complex(struct SComplex SUM){

	printf("The sum of two complex number are: %.1lf + %.1lfi",SUM.m_real, SUM.m_img);



}
int main() {


	struct SComplex v1, v2, sum;

	v1=Read_complex("Enter 1st complex number");
	v2=Read_complex("Enter 2nd complex number");
	sum = add_complex(v1, v2);
	print_complex(sum);





	return 0;

}
