//
//  BinaryTree.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/12.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "BinaryTree.h"
/*
 创建一个节点,没什么特别的
 Creat a new TreeNode, nothing special.
 */
TreeNode* creatTreeNode(int32_t val)
{
    TreeNode* re = malloc(sizeof(TreeNode));
    re->val = val;
    re->left = NULL;
    re->right = NULL;
    return re;
}
/*
 根据LeetCode风格的输入创建一颗二叉树，返回root，暂规定节点少于100个。
 Creat a new BinaryTree based on the LeetCode-style string, returing root.
 e.g: "[3,4,5,5,4,null,7]"
 */

TreeNode* creatTree (const char *in)
{
    if (!in)
        return NULL;
    struct TreeNode** n = malloc(sizeof(struct TreeNode*) * 100);
    //n指向一个包含树所有节点指针的指针数组，方便通过编号确定父子关系—————因为输入是完全二叉树的顺序,\
    所以n[i]的左右子树分别为n[2*i+1]和n[2*i+2]
    memset(n, 0, sizeof(struct TreeNode*) * 100);
    char *input = malloc(400);
    char *input_base = input;
    strcpy(input, in);
    if (*input++ != '[') {
        printf("It seems input is NOT leetcode BinaryTree style!\n");
        return NULL;
    }
    int32_t cnt = 0;
    for(char *s = strtok(input, ","); s ; cnt++, s = strtok(NULL, ","))
        if (!strncmp(s, "null", 4)) {
            n[cnt] = NULL;
        }
        else {
            int32_t val = atoi(s);
            n[cnt] = creatTreeNode(val);
        }
    for (int i = 0; i < cnt; i++) {
        if (2 * i + 1 < cnt && n[i])
            n[i]->left = n[2 * i + 1];
        if (2  * i + 2 < cnt && n[i])
            n[i]->right = n[2 * i + 2];
    }
    
    TreeNode *re = n[0];
    free(n);
    free(input_base);
    return re;
}
void freeTree(TreeNode* root)
{
    if (root->left)
        freeTree(root->left);
    if (root->right)
        freeTree(root->right);
    free(root);
}
static void printTreePre_recurse(TreeNode *root)
 {
     if (!root) {
         printf("Tree is empty!\n");
         return;
     }
    printf("%d, ", root->val);
    if (root->left)
        printTreePre_recurse(root->left);
    if (root->right)
        printTreePre_recurse(root->right);
}

void printTreePre(TreeNode *root)
{
    if (!root) {
        printf("Tree is empty!\n");
        return;
    }
    stack *s = creatStack(200);
    pushStack(root, s);
    while (sizeofStack(s)) {
        TreeNode* cur = (TreeNode*)popStack(s);
        printf("%d, ",cur->val);
        if (cur->right)
            pushStack(cur->right, s);
        if (cur->left)
            pushStack(cur->left, s);
    }
    printf("\n");
}

static void printTreeMid_recurse(TreeNode* root)
{
    if (!root) {
        printf("Tree is empty!\n");
        return;
    }
    if (root->left)
        printTreeMid_recurse(root->left);
    printf("%d, ", root->val);
    if (root->right)
        printTreeMid_recurse(root->right);
}

void printTreeMid(TreeNode *root)
{
    if (!root) {
        printf("Tree is empty!\n");
        return;
    }
    stack *s = creatStack(200);
    while (sizeofStack(s) || root) {
        while (root) {
            pushStack(root, s);
            root = root->left;
        }
        root = popStack(s);
        printf("%d, ", root->val);
        root = root->right;
    }
    printf("\n");
    return;

}
void printTreePost(TreeNode *root) {
    if (root->left)
        printTreePost(root->left);
    if (root->right)
        printTreePost(root->right);
    printf("%d, ", root->val);
}

void test_bt(void)
{
    printf("BinaryTree test starts!\n");
//    printTreePre(NULL);
    printTreeMid(creatTree("[3,4,5,5,4,null,7]"));
    printTreeMid_recurse(creatTree("[3,4,5,5,4,null,7]"));
    return;
}
