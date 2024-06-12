#define _CRT_SECURE_NO_WARNINGS
#include"Vector.h"
#include<stdio.h>

#define DEFAULT_CAPACITY 8
#define PREALLOC_MAX 1024
//���캯��
Vector* vector_create(void)
{
	Vector* v = malloc(sizeof(Vector));
	if (!v)
	{
		printf("Error:malloc failed in vector create.");
		exit(1);
	}
	v->elements = malloc(DEFAULT_CAPACITY*sizeof(E));
	if (!v->elements)
	{
		printf("Error:malloc failed in vector create.");
		exit(1);
	}
	v->size = 0;
}
//��������
void vector_destroy(Vector* v)
{
	free(v->elements);
	free(v);
}
void grow_capacity(Vector* v)
{
	int new_capacity = v->capacity < PREALLOC_MAX ? v->capacity << 1 : v->capacity + PREALLOC_MAX;
	E *p = realloc(v->elements,new_capacity*sizeof(E));
	if (!p)
	{
		printf("Error:realloc failed in grow_capacity.");
		exit(1);
	}
	v->elements= p;
	v->capacity = new_capacity;
}
//��������һ��Ԫ��
void push_back(Vector* v, E val)
{
	if (v->size == v->capacity)
	{
		grow_capacity(v);
	}
	v->elements[v->size++] = val;
}
//��ǰ�����һ��Ԫ��
void push_front(Vector* v, E val)
{
	if ( v->size ==v->capacity)
	{
		grow_capacity(v);
	}
	v->size++;
	for (int i=0; i < (v->size-1); i++)
	{
		v->elements[v->size - i] = v->elements[v->size - 1 - i];
	}
	v->elements[0] = val;
}
//ɾ�����һ��Ԫ�أ�������
E pop_back(Vector* v)
{
	E i = v->elements[v->size-1];
	v->elements[v->size-1] = 0;
	v->size--;
	return i;
}
//ɾ����һ��Ԫ�ء�������
E pop_front(Vector* v)
{
	E i = v->elements[0];
	v->elements[0] = 0;
	for (int j = 0; j< (v->size - 2); j++)
	{
		v->elements[j] = v->elements[j+1];
	}
	v->size--;
	return i;
}