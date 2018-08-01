//
//  538.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/7/29.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "538.h"
int32_t sum;
static void subProcess(struct TreeNode* root)
{
    if (root->right)
        subProcess(root->right);
    sum += root->val;
    root->val = sum;
    if (root->left)
        subProcess(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root)
{
    sum = 0;
    if (root)
        subProcess(root);
    return root;
}

void ut_538(void)
{
    struct TreeNode* root = creatTree("[1,0,4,-2,null,3]");
    convertBST(root);
    free(root);
}
