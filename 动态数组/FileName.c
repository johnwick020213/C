#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Vector.h"

/*×¢ÊÍ*/

int main(void)
{
	Vector* v = vector_create();
	push_back(v, 0);
	push_back(v, 1);
	push_back(v, 2);
	push_back(v, 3);
	push_back(v, 4);
	push_front(v, -1);
	E I=pop_back(v);
	E J=pop_front(v);
	return 0;
}