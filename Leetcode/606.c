//
//  606.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/7/8.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "606.h"
char* tmp;

static void preorder(struct TreeNode* root, char* str)
{
    if (!root) {
        return;
    }
    sprintf(tmp, "%d", root->val);
    strcat(str, tmp);
    if (root->right || root->left) {
        strcat(str, "(");
        preorder(root->left, str);
        strcat(str, ")");
    }
    
    if (root->right) {
        strcat(str, "(");
        preorder(root->right, str);
        strcat(str, ")");
    }
}

char* tree2str(struct TreeNode* t)
{
    char* str = malloc(1000);
    tmp = malloc(50);
    memset(str, 0, 1000);
    preorder(t, str);
    free(tmp);
    return str;
}
