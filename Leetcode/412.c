//
//  412.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "412.h"
char** fizzBuzz(int n, int* returnSize) {
    uint32_t i = 1;
    *returnSize = n;
    char **re = malloc(n * sizeof(size_t));
    for (;i <= n; i++) {
        re[i - 1] = malloc(20);
        uint32_t m3 = i % 3;
        uint32_t m5 = i % 5;
        if (!m3 && !m5) {
            strcpy(re[i - 1], "FizzBuzz");
            continue;
        }
        if (!m3) {
            strcpy(re[i - 1], "Fizz");
            continue;
        }
        if (!m5) {
            strcpy(re[i - 1], "Buzz");
            continue;
        }
        sprintf(re[i - 1], "%d", i);
    }
    return re;
};
