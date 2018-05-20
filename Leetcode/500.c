//
//  500.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "500.h"
const int a[] = {0x000002, 0x000004, 0x000004, 0x000002, 0x000001, 0x000002, 0x000002, 0x000002, 0x000001, 0x000002, 0x000002, 0x000002, 0x000004, 0x000004, 0x000001, 0x000001, 0x000001, 0x000001, 0x000002, 0x000001, 0x000001, 0x000004, 0x000001, 0x000004, 0x000001, 0x000004, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x000002, 0x000004, 0x000004, 0x000002, 0x000001, 0x000002, 0x000002, 0x000002, 0x000001, 0x000002, 0x000002, 0x000002, 0x000004, 0x000004, 0x000001, 0x000001, 0x000001, 0x000001, 0x000002, 0x000001, 0x000001, 0x000004, 0x000001, 0x000004, 0x000001, 0x000004,};

char** findWords(char** words, int wordsSize, int* returnSize) {
    int32_t i = 0;
    char** re = malloc(6000);
    *returnSize = 0;
    for (; i < wordsSize; i++) {
        uint32_t len = (uint32_t)strlen(words[i]);
        int32_t j = 0;
        uint32_t n = 0;
        for (; j < len; j++) {
            n |= a[words[i][j] - 'A'];
        }
        if(!(n ^ (n & -n))) {
            re[*returnSize] = malloc(len);
            strcpy(re[*returnSize], words[i]);
            (*returnSize)++;
        }
    }
    return re;
}
