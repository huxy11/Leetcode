//
//  669.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/12.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "669.h"
TreeNode* trim(TreeNode* pre, int l, int r)
{
    if (!pre)
        return NULL;
    while (pre && (pre->val < l || pre->val > r)) {
        if (pre->val < l)
            pre = pre->right;
        else
            pre = pre->left;
    }
    if (pre) {
        pre->left = trim(pre->left, l, r);
        pre->right = trim(pre->right, l, r);
    }
    return pre;
}

struct TreeNode* trimBST(TreeNode* root, int L, int R)
{
    if (!root)
        return NULL;
    while (root && (root->val > R || root->val < L)) {
        for (;root &&root->val > R; root = root->left);
        for (;root && root->val < L; root = root->right);
    }
    trim(root, L, R);
    return root;
}

void test_669(void)
{
    TreeNode* t = creatTree("[3,1,4,null,2]");
    trimBST(t, 3, 4);
    printTreePre(t);
    freeTree(t);
}

