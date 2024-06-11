#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "BST.h"
#include <stdlib.h>

/*×¢ÊÍ*/

int main(void)
{
	BST* bst = bst_create();

	bst_insert(bst, 9);
	bst_insert(bst, 5);
	bst_insert(bst, 3);
	bst_insert(bst, 43);
	bst_insert(bst, 13);
	bst_insert(bst, 53);
	bst_insert(bst, 9);

	bst_inorder(bst);
	bst_preorder(bst);
	bst_postorder(bst);
	bst_levelorder(bst);
	bst_levelorder2(bst);
	int i = maxDepth(bst->root);

	return 0;
}