//
//  821.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/19.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "821.h"

int* shortestToChar(char* S, char C, int* returnSize) {
    uint32_t len = (uint32_t)strlen(S);
//    int* re = malloc(sizeof(int) * len);
    int* re = malloc(40000);
    int32_t i = 0;
    for (;i < len; i++) {
        if (S[i] == C)
            re[i] = 0;
        else
            re[i] = 0x7FFFFFFF;
    }
    for (i = 0; i < len; i++)
        if (re[i] == 0) {
            int l = i - 1;
            int n = 1;
            while (l >= 0 && re[l] > n) {
                re[l--] = n++;
            }
            int r = i + 1;
            n = 1;
            while (n < len && re[r] > n) {
                re[r++] = n++;
            }
        }
    *returnSize = len;
    return re;
}
