#include<stdbool.h>
typedef int E;

typedef struct {
    E* elements;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// API
Queue* queue_create(int capacity);
void queue_destroy(Queue* q);

void queue_push(Queue* q, E val);
E queue_pop(Queue* q);
E queue_peek(Queue* q);

bool queue_empty(Queue* q);
void queue_print(Queue* q);