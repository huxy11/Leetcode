//
//  682.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "682.h"
int calPoints(char** ops, int opsSize) {
    uint32_t i = 0;
    uint32_t n = -1;
    int32_t sum = 0;
    int32_t a[1000] = {};
    for (int j = 0; j < 1000; j++)
        if (a[j])
            printf("%d is not zero!\n", j);
    for (; i < opsSize; i++) {
        switch (ops[i][0]) {
            case '+':
//                assert(n > 0);
                n++;
                a[n] = a[n - 1] + a[n -2];
                break;
            case 'D':
//                assert(n > -1);
                n++;
                a[n] = 2 * a[n - 1];
                break;
            case 'C':
//                assert(n > -1);
                a[n] = 0;
                n--;
                break;
            default:
                n++;
                a[n] = atoi(ops[i]);
                break;
        }
    }
    for (i = 0; i <= n; i++) {
        sum += a[i];
    }

    return sum;
}
