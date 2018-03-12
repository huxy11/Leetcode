//
//  655.c
//  Leetcode
//
//  Created by 胡星宇 on 2017/8/8.
//  Copyright © 2017年 胡星宇. All rights reserved.
//

#include "655.h"
#include <stdlib.h>

#define MAX(x, y) x > y ? x : y

int findDepth(struct TreeNode* root)
{
    if (!root)
        return -1;
    return MAX(findDepth(root->left), findDepth(root->right)) + 1;
}

char*** printTree(struct TreeNode* root, int** columnSizes, int* returnSize) {
    
    return 0;
}

struct TreeNode* newNode()
{
    struct TreeNode* n = malloc(sizeof(struct TreeNode));
    n->left = NULL;
    n->right = NULL;
    n->val = 1;
    return n;
}
void test_655()
{
    struct TreeNode *root = newNode();
    
    root->left = newNode();
//    printf("%d\n", findDepth(root));
    root->right = newNode();
    root->right->left = newNode();
//    printf("%d\n", findDepth(root));
    root->right->right = newNode();
    root->right->right->right = newNode();
    printf("%d\n", findDepth(root));
  
    return;
}
