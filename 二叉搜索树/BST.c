#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#include"que.h"

BST* bst_create(void)
{
	return calloc(1,sizeof(BST));
}
void bst_destroy(BST* tree)
{
	free(tree);
}

void bst_insert(BST* tree, K key)
{
	TreeNode*parent=NULL;
	TreeNode* curr = tree->root;
	int cmp ;

	while (curr)
	{
		cmp = key - curr->key;
		if (cmp < 0)
		{
			parent = curr;
			curr = curr->left;
		}
		else if (cmp > 0)
		{
			parent = curr;
			curr = curr->right;
		}
		//key已经存在
		else
		{
			return;
		}
		
	}//curr==NULL
	
	TreeNode* new_node = calloc(1,sizeof(TreeNode));
	new_node->key = key;

	if (parent == NULL)
	{
		tree->root = new_node;
	}
	else
	{
		cmp = key - parent->key;
		if (cmp>0)
		{
			parent->right = new_node;
		}
		else
		{
			parent->left = new_node;
		}
	}
	
}
TreeNode* bst_search(BST* tree, K key)
{
	TreeNode*curr=tree->root;
	while (curr)
	{
		int cmp = key - curr->key;
		if (cmp < 0)
		{
			curr = curr->left;
		}
		else if (cmp > 0)
		{
			curr = curr->right;
		}
		else
			return curr;
	}
	return NULL;
}
void bst_delete(BST* tree, K key)
{
	TreeNode*parent=NULL;
	TreeNode* curr = tree->root;
	while (curr)
	{
		int cmp = key - curr->key;
		if (cmp < 0)
		{
			parent = curr;
			curr = curr->left;
		}
		else if (cmp > 0)
		{
			parent = curr;
			curr = curr->right;
		}
		else
		{
			break;
		}
	}

	//2.退化
	if (curr->left && curr->right)
	{
		TreeNode* minp = curr;
		TreeNode* min = curr->right;
		while (min->left)
		{
			minp = min;
			min = min->left;
		}
		curr->key = min->key;
		curr = min;
		parent = minp;//跟踪待删除元素
	}
	TreeNode* child = curr->left ? curr->left : curr->right;//如果没有执行退化则curr->left不一定为NULL

	if (parent == NULL)
	{
		tree->root = child;
	}
	else
	{
		int cmp = curr->key - parent->key;
		if (cmp < 0)
		{
			parent->left = child;
		}
		else if (cmp > 0)
		{
			parent->right = child;
		}
		else
		{
			parent->right = child;
		}
		free(curr);
	}
}

// 深度优先遍历
void preorder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->key);
	preorder(root->left);
	preorder(root->right);
}
void bst_preorder(BST* tree)
{
	preorder(tree->root);
	printf("\n");
}
void inorder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ", root->key);
	inorder(root->right);
}
void bst_inorder(BST* tree)
{
	inorder(tree->root);
	printf("\n");
}
void postorder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->key);
}
void bst_postorder(BST* tree)
{
	postorder(tree->root);
	printf("\n");;
}
// 广度优先遍历
void bst_levelorder(BST* tree)
{
	Queue* q = queue_create(100);
	
	queue_push(q, tree->root);
	
	while (!queue_empty(q)) {
		
		TreeNode* node = queue_pop(q);
		printf("%d ", node->key);
		
		if (node->left) {
			queue_push(q, node->left);
		}
		
		if (node->right) {
			queue_push(q, node->right);
		}
	} 
	printf("\n");
}
void bst_levelorder2(BST* tree)
{
	Queue* q = queue_create(100);

	queue_push(q, tree->root);

	int currentLevelNodes = 1;
	int nextLevelNodes = 0;

	while (!queue_empty(q)) {

		TreeNode* node = queue_pop(q);
		printf("%d ", node->key);

		if (node->left) {
			queue_push(q, node->left);
			nextLevelNodes++;
		}

		if (node->right) {
			queue_push(q, node->right);
			nextLevelNodes++;
		}
		currentLevelNodes--;

		if (currentLevelNodes == 0) {
			printf("\n"); // 输出换行符表示当前层已经输出完毕
			currentLevelNodes = nextLevelNodes;
			nextLevelNodes = 0;
		}
	}
	printf("\n");
}

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	Queue* q = queue_create(100);

	queue_push(q, root);

	int depth = 0;
	int currentLevelNodes = 1;
	int nextLevelNodes = 0;

	while (!queue_empty(q)) {

		TreeNode* node = queue_pop(q);

		if (node->left) {
			queue_push(q, node->left);
			nextLevelNodes++;
		}

		if (node->right) {
			queue_push(q, node->right);
			nextLevelNodes++;
		}
		currentLevelNodes--;

		if (currentLevelNodes == 0) {
			depth++;
			currentLevelNodes = nextLevelNodes;
			nextLevelNodes = 0;
		}
	}
	return depth;
}