//
//  226.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "226.h"
static void it(struct TreeNode* root)
{
    struct TreeNode *tmp = 0;
    if (root->right)
        tmp = root->right;
    root->right =root->left;
    root->left =tmp;
    if (root->left)
        it(root->right);
    if (root->right)
        it(root->left);
}


struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root)
        return NULL;
    return root;
}
