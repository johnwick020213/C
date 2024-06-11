#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"que.h"

/*×¢ÊÍ*/

int main(void)
{
	Queue* q = queue_create(8);
	queue_push(q, 1);
	queue_push(q, 2);
	queue_push(q, 3);
	queue_push(q, 4);
	queue_push(q, 5);
	queue_push(q, 6);
	queue_push(q, 7);
	queue_print(q);
	int i=queue_pop(q);
	queue_print(q);
	int j=queue_peek(q);
	bool k = queue_empty(q);
	return 0;
}