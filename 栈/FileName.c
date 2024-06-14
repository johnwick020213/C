#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"stack.h"

/*×¢ÊÍ*/

int main(void)
{
	Node* top = stack_create();
	;
	stack_push(&top,2);
	stack_push(&top,3);
	stack_push(&top,4);
	stack_push(&top,5);
	stack_push(&top,6);
	return 0;
}