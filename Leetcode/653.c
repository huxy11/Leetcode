//
//  653.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/26.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "653.h"
struct TreeNode* findN(struct TreeNode* root, int n)
{
    while (root && root->val != n) {
        if (root->val > n)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
bool findTargetSub(struct TreeNode* root,struct TreeNode* snode, int k)
{
    if (!snode)
        return false;
    int32_t j = k - snode->val;
    if(j == snode->val)
        return  findTargetSub(root, snode->left, k) || findTargetSub(root, snode->right, k);
    if (findN(root, j))
        return true;
    else {
        return findTargetSub(root, snode->left, k) || findTargetSub(root, snode->right, k);
    }
}

bool findTarget(struct TreeNode* root, int k)
{
    if (!root)
        return false;
    return findTargetSub(root, root, k);
}
