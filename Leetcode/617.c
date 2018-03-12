//
//  617.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/12.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "617.h"

TreeNode* mergeTrees(TreeNode* t1, struct TreeNode* t2)
{
    mergeNode(t1, t2);
    return t1;
}

void mergeNode(struct TreeNode *n1, struct TreeNode *n2)
{
    if (n2) {
        printf("n1 = %d, n2 = %d\n", n1->val, n2->val);
        n1->val += n2->val;
        if (!n1->left && n2->left) {
            n1->left = malloc(sizeof(TreeNode));
            n1->left->val = 0;
        }
        if (!n1->right && n2->right) {
            n1->right = malloc(sizeof(TreeNode));
            n1->right->val = 0;
        }
        if (n1->left)
            mergeNode(n1->left, n2->left);
        if (n1->right)
            mergeNode(n1->right, n2->right);
    }
}

void test_617(void)
{
    TreeNode *s1 = creatTree("[1,3,2,5]");
    TreeNode *s2 = creatTree("[2,1,3,null,4,null,7]");
    mergeTrees(s1, s2);
    printTreePre(s1);
}
