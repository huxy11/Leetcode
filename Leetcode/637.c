//
//  637.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/14.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "637.h"

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double* re = malloc(sizeof(double) * 200);
    int32_t cnt1 = 0, top1 = 0, cnt2 = 0, top2 = 0, recnt = 0;
    int64_t sum = 0;
    struct TreeNode *s1[200];
    struct TreeNode *s2[200];
    s1[0] = root;
    top1++;
    while (top1 != 0 ||top2 != 0) {
        while (cnt1 < top1) {
            sum += s1[cnt1]->val;
            if (s1[cnt1]->left)
                s2[top2++] = s1[cnt1]->left;
            if (s1[cnt1]->right)
                s2[top2++] = s1[cnt1]->right;
            cnt1++;
        }
        if (top1 != 0) {
            re[recnt++] = (double)sum / top1;
            (*returnSize)++;
        }
        sum = 0;
        cnt2 = 0;
        top1 = 0;
        while (cnt2 < top2) {
            sum += s2[cnt2]->val;
            if (s2[cnt2]->left)
                s1[top1++] = s2[cnt2]->left;
            if (s2[cnt2]->right)
                s1[top1++] = s2[cnt2]->right;
            cnt2++;
        }
        if (top2 != 0) {
            re[recnt++] = (double)sum / top2;
            (*returnSize)++;
        }
        sum = 0;
        cnt1 = 0;
        top2 = 0;
    }
    return re;
}

void test_637(void)
{
    TreeNode* root = creatTree("[2147483647,2147483647,2147483647]");
    int32_t *a = malloc(sizeof(int32_t));
    double* re = averageOfLevels(root, a);
    printf("%d\n", *a);
    for (int i = 0; i < *a; i++)
        printf("%f\n", re[i]);
}
