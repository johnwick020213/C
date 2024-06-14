#include<stdio.h>
#include<stdbool.h>
#include"stack.h"


Stack* stack_create(void)
{

	return calloc(1, sizeof(Stack£©;
}
void stack_destroy(Stack* s)
{
	free(s);
}

void stack_push(Stack* s, E val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Failed to allocate memory for new node");
        exit(1);
    }
    new_node->data = val;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

 
E stack_pop(Stack* s) {
    if (stack_empty(s)) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(1);
    }
    Node* temp = s->top;
    E val = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;
    return val;
}

// ·µ»ØÕ»¶¥ÔªËØ
E stack_peek(Stack* s) {
    if (stack_empty(s)) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(1);
    }
    return s->top->data;
}

// ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
bool stack_empty(Stack* s) {
    return s->top == NULL;
}