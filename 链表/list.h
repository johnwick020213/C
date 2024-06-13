#include<stdbool.h>
typedef int E;

typedef struct node
{
	E data;
	struct node* next;
}Node;

typedef struct
{
	Node* head;
	Node* tail;
}List;

List* list_create(void);
void list_destory(List* list);

void add_before_head(List** list, E val);
void add_back_tail(List** plist, E val);
void display_list(Node* list);
Node* search_list(Node* list, int val);
void free_list(Node* list);
int middleElement(Node* list);
bool hasCircle(Node* list);
Node* reverse(Node* list);
Node* mergeTwoLists(Node* list1, Node* list2);
