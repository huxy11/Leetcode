//
//  BST.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/18.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "BST.h"

TreeNode* minBST(TreeNode* root)
{
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* maxBST(TreeNode* root)
{
    while (root && root->right) {
            root = root->right;
    }
    return root;
}
static TreeNode** min(TreeNode **root)
{
    TreeNode **cur;
    cur = root;
    while (*cur && (*cur)->left) {
        cur = &(*cur)->left;
    }
    return cur;
}
static TreeNode** max(TreeNode *root)
{
    if (!root)
        return NULL;
    TreeNode **cur;
    cur = &root;
    while (*cur && (*cur)->right) {
        cur = &(*cur)->right;
    }
    return cur;
}
TreeNode* findBST(TreeNode* root, int32_t val)
{
    while (root && root->val != val) {
        if (root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
void insert(TreeNode* root, int32_t val)
{
    while (root) {
        if (root->val > val) {
            if (root->left)
                root = root->left;
            else {
                root->left = creatTreeNode(val);
                break;
            }
        }
        if (root->val < val) {
            if (root->right)
                root = root->right;
            else {
                root->right = creatTreeNode(val);
                break;
            }
        }
    }
    return;
}
void deleteBST(TreeNode* root, int32_t val)
{
    TreeNode **cur;
    TreeNode **replace, *tmp;
    cur = &root;
    while (*cur) {
        if ((*cur)->val == val) {
             replace = min(&(*cur)->right);
//            printf("min = %d\n", (*replace)->val);
            tmp = *replace;
//            (*replace)->val = 100;
            printf("%d\n", root->right->right->val);
            *replace = (*replace)->right;
            tmp->left = (*cur)->left;
            tmp->right =(*cur)->right;
            *replace = *cur;
            *cur = tmp;
            free(*cur);
        }
        if ((*cur)->val > val)
            cur = &(*cur)->left;
        else
            cur = &(*cur)->right;
    }
    /*
    TreeNode *cur, *pre;
    cur = root;
    while (cur) {
        if (cur->val == val) {
            
        }
        if (cur->val > val) {
            pre = cur;
            cur = cur->left;
        }
        if (cur->val < val){
            pre = cur;
            cur = cur->right;
        }
    }
     */
}

void test_BST(void)
{
    TreeNode* root = creatTree("[5,3,8,1,4,6,9]");
    printf("%d\n", minBST(root)->val);
    printf("%d\n", (*min(&root))->val);
    printf("%d\n", maxBST(root)->val);
    TreeNode* re = findBST(root, 3);
    printf("%d\n", re->val);
    re = findBST(root, 11);
    if (!re)
        printf("not found!\n");
    insert(root, 11);
    re = findBST(root, 11);
    printf("%d\n", re->val);
    deleteBST(root, 8);
    return;
}
