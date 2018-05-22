//
//  104.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "104.h"

struct st {
    struct TreeNode* val;
    uint32_t n;
};

int maxDepth(struct TreeNode* root) {
    if (!root)
        return 0;
    struct st a[40000];
    uint32_t l = 0;
    uint32_t r = 1;
    a[0].val = root;
    a[0].n = 1;
    while (l < r) {
        if (a[l].val->left) {
            a[r].val = a[l].val->left;
            a[r++].n = a[l].n + 1;
        }
        if (a[l].val->right) {
            a[r].val = a[l].val->right;
            a[r++].n = a[l].n + 1;
        }
        l++;
    }
    return a[l - 1].n;
}
