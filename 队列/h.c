#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"que.h"
#define MAX_CAPACITY 1024
Queue* queue_create(int capacity)
{
	Queue* queue = malloc(sizeof(Queue));
	if (!queue)
	{
		printf("ERROR:failed in queue_create");
		exit(1);
	}
	queue->elements = malloc(capacity * sizeof(E));
	if (!queue->elements)
	{
		printf("ERROR:failed in queue_create");
		exit(1);
	}
	queue->front = 0; 
	queue->rear = 0;
	queue->capacity = capacity;
	queue->size = 0;
	return queue;
}
void queue_destroy(Queue* q)
{
	free(q->elements);
	free(q);
}
void queue_resize(Queue* q, int new_capacity) {
	E* new_elements = (E*)malloc(new_capacity * sizeof(E));
	if (!new_elements) {
		printf("ERROR: 内存分配失败\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < q->size; ++i) {
		new_elements[i] = q->elements[(q->front + i) % q->capacity];
	}
	free(q->elements);
	q->elements = new_elements;
	q->front = 0;
	q->rear = q->size - 1;
	q->capacity = new_capacity;
}//扩容
void queue_push(Queue* q, E val)
{
	if (q->size == q->capacity)
	{
		int new_capacity = q->capacity < MAX_CAPACITY ? q->capacity * 2 : q->capacity + MAX_CAPACITY;
		queue_resize(q, new_capacity);
	}
	q->elements[q->rear]=val;
	q->rear= (q->rear + 1) % q->capacity;
	q->size++;
}
E queue_pop(Queue* q)
{
	if (q->size == 0)
	{
		printf("pop failed");
		exit(1);
	}
	E val = q->elements[q->front];
	q->front = (q->front+1)%q->capacity;
	q->size--;
	return val;
}
E queue_peek(Queue* q)
{
	if (q->size == 0) {
		printf("队列为空！\n");
		exit(EXIT_FAILURE);
	}
	return q->elements[q->rear-1];
}

bool queue_empty(Queue* q)
{
	return q->size==0;
}
void queue_print(Queue* q) {
	int size = q->size;
	int front = q->front;
	while (size) {
		printf("%d --> ", q->elements[front]);
		front = (front + 1) % q->capacity;
		size--;
	}
	printf("NULL\n");
}