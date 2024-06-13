#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
#include<stdio.h>
#include<stdbool.h>
//��������
List* list_create(void)
{
	return calloc(1,sizeof(List));
}
//��������
void list_destory(List* list)
{
	free(list);
}

void add_before_head(List** plist, E val)
{
	Node* new_node = malloc(sizeof(Node));
	if (!new_node)
	{
		printf("ERROR:failed in add_before_head");
		exit(1);
	}
	new_node->data = val;
	new_node->next = *plist;
	*plist = new_node;
}
void add_back_tail(List** plist, E val)
{
	Node* new_node = malloc(sizeof(Node));
	if (!new_node)
	{
		printf("ERROR:failed in add_back_tail\n");
		exit(1);
	}
	new_node->data = val;
	new_node->next = NULL;

	if (*plist == NULL) {
		*plist = new_node;
	}
	else {
		Node* current = *plist;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
}

void display_list(Node* list)
{
	Node* curr = list;
	while (curr != NULL)
	{
		printf("|  % d  |----> ", curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}
Node* search_list(Node* list, int val)
{
	Node* curr = list;
	while (curr != NULL)
	{
		if (curr->data == val)
		{
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}
void free_list(Node* list)
{
	Node* curr = list;
	while (curr != NULL)
	{
		Node* next = curr->next;
		free(curr);
		curr = next;
	}
}
int middleElement(Node* list)
{
	Node* curr = list;
	int length = 0;

	while (curr != NULL)
	{
		curr = curr->next;
		length++;
	}

	curr = list;

	for (int j = 0; j < length / 2; j++)
	{
		curr = curr->next;
	}

	return curr->data;
}

bool hasCircle(Node* list)
{
	Node* slow = list;
	Node* fast = list;
	while (fast != NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		Node* cur = fast->next;
		fast = cur->next;
		if(slow==fast)
			return true;

	}
	return false;
}
Node* reverse(Node* list)
{
	Node* pre = NULL;
	Node* cur = list;
	while(cur)
	{
		Node* next = cur->next;//��¼��Ҫ��ת��Ԫ��
		cur ->next = pre;//��ת��ǰָ�볯������ָ��ǰһ��Ԫ��
		pre = cur;//��ǰһ��Ԫ����Ϊ��ǰԪ��
		cur = next;//��ǰָ�����
	}
	return pre;
	
}
Node* mergeTwoLists(Node* list1, Node* list2)
{
	Node* dummy = (Node*)malloc(sizeof(Node));
	if (dummy == NULL) {
		printf("���󣺷����ƽڵ�ʧ��\n");
		exit(1);
	}
	dummy->data = 0;
	dummy->next = NULL;
	Node* tail = dummy; // ��β����ʼ��Ϊ�ƽڵ㣬�������ƽڵ����һ���ڵ�
	while (list1 && list2)
	{
		if (list1->data < list2->data)
		{
			tail->next = list1; // ��β�����ӵ���С�Ľڵ�
			list1 = list1->next;
		}
		else
		{
			tail->next = list2; // ��β�����ӵ���С�Ľڵ�
			list2 = list2->next;
		}
		tail = tail->next; // ��β���ƶ�����һ���ڵ�
	}
	// ���ʣ��Ľڵ�
	tail->next = (list1 != NULL) ? list1 : list2;
	// ���غϲ���������ͷ�������ƽڵ�֮��Ľڵ�
	return dummy->next;
}
