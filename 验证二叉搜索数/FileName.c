#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

/*注释*/
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


int minroot(struct TreeNode* root)
{
    if (root->left!=NULL)
        return minroot(root->left);
    else
        return root->val;
}
int maxroot(struct TreeNode* root)
{
    if (root->right!=NULL)
        return maxroot(root->right);
    else
        return root->val;
}
bool isValidBST(struct TreeNode* root)
{
    if(root==NULL)
        return true;
    else
    {
        if (root->right == NULL && root->left == NULL)
            return true;
        if (root->left != NULL&&root->right==NULL&& root->left->val < root->val && maxroot(root->left) < root->val)
            return isValidBST(root->left);
        if (root->right != NULL&&root->left==NULL && root->right->val > root->val && minroot(root->right) > root->val)
            return isValidBST(root->right);
        if(root->left != NULL&& root->right != NULL && root->left->val < root->val && maxroot(root->left) < root->val && root->right->val > root->val && minroot(root->right) > root->val)
            return isValidBST(root->left)&&isValidBST(root->right);
        else
            return false;
    }
        
}
int main()
{
    // 创建二叉树
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 32;

    root->left = malloc(sizeof(struct TreeNode));
    root->left->val = 26;
    root->left->left = malloc(sizeof(struct TreeNode));
    root->left->left->val = 19;
    root->left->left->left = NULL;
    root->left->left->right = malloc(sizeof(struct TreeNode));
    root->left->left->right->val = 27;
    root->left->left->right->left = NULL;
    root->left->left->right->right = NULL;
    root->left->right = NULL;

    root->right = malloc(sizeof(struct TreeNode));
    root->right->val = 47;
    root->right->left = NULL;
    root->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->val = 56;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    root->right->right->right = NULL;

    // 调用isValidBST函数
    bool result = isValidBST(root);

    // 打印结果
    printf("Is the given binary tree a valid BST? %s\n", result ? "true" : "false");

    // 释放二叉树的内存
    // （在实际应用中可能需要编写函数来进行内存释放）
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);

    return 0;
}