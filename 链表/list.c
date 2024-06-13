#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
#include<stdio.h>
#include<stdbool.h>
//创建链表
List* list_create(void)
{
	return calloc(1,sizeof(List));
}
//析构函数
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
		Node* next = cur->next;//记录需要反转的元素
		cur ->next = pre;//反转当前指针朝向，让他指向前一个元素
		pre = cur;//将前一个元素设为当前元素
		cur = next;//当前指针后移
	}
	return pre;
	
}
Node* mergeTwoLists(Node* list1, Node* list2)
{
	Node* dummy = (Node*)malloc(sizeof(Node));
	if (dummy == NULL) {
		printf("错误：分配哑节点失败\n");
		exit(1);
	}
	dummy->data = 0;
	dummy->next = NULL;
	Node* tail = dummy; // 将尾部初始化为哑节点，而不是哑节点的下一个节点
	while (list1 && list2)
	{
		if (list1->data < list2->data)
		{
			tail->next = list1; // 将尾部连接到较小的节点
			list1 = list1->next;
		}
		else
		{
			tail->next = list2; // 将尾部连接到较小的节点
			list2 = list2->next;
		}
		tail = tail->next; // 将尾部移动到下一个节点
	}
	// 添加剩余的节点
	tail->next = (list1 != NULL) ? list1 : list2;
	// 返回合并后的链表的头部，即哑节点之后的节点
	return dummy->next;
}
