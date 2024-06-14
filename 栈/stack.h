#include<stdbool.h>
typedef int E;

typedef struct node {
    E data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

// API
Stack* stack_create(void);
void stack_destroy(Stack* s);

void stack_push(Stack* s, E val);
E stack_pop(Stack* s);
E stack_peek(Stack* s);

bool stack_empty(Stack* s);
