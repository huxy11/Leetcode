//
//  784.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "784.h"

char** letterCasePermutation(char* S, int* returnSize) {
    char** re = malloc(sizeof(size_t) * 4096);
    int32_t i;
    uint32_t mask = 1 << 5;
    *returnSize = 1;
    size_t len = strlen(S);
    re[0] = malloc(len + 1);
    strcpy(re[0], S);
    for (i = len - 1; i >= 0; i--) {
        if ('A' <= S[i] && S[i] <= 'z') {

            uint32_t j = 0;
            for (; j < *returnSize; j++) {
                re[j][i] |= mask;
            }
            for (j = *returnSize; j < *returnSize * 2; j++){
                re[j] = malloc(len) + 1;
                strcpy(re[j],re[j - *returnSize]);
                re[j][i] &= ~mask;
            }
            *returnSize *= 2;
        }
    }
    return re;
}
