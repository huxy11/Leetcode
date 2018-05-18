//
//  728.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/18.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "728.h"

char isSDN(const int number)
{
    int32_t n = number;
    while (n) {
        int32_t m = n % 10;
        n /= 10;
        if (!m || (number % m)) {
            return 0;
        }
    }
    return 1;
}

int* selfDividingNumbers(int left, int right, int* returnSize)
{
    uint32_t n = 0, sum = 0;
    int32_t* re = malloc((right - left) * 4);
    for (n = left; n <= right; n++) {
        if (isSDN(n))
            re[sum++] = n;
    }
    *returnSize = sum;
    return re;
}
