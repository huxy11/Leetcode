//
//  561.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/18.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "561.h"
static void qs(int32_t *a, int32_t lo, int32_t hi)
{
    int32_t i = lo;
    int32_t j = hi;
    while (i < j) {
        int32_t tmp;
        while (i < j && a[i] <= a[j])
            i++;
        if (i < j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        if (i == j)
            j--;
        while (i < j && a[i] <= a[j])
            j--;
        if (i < j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        if (i == j)
            i++;
    }
    if (i < hi)
        qs(a, i ,hi);
    if (j > lo)
        qs(a, lo, j);
}

int arrayPairSum(int* nums, int numsSize)
{
    qs(nums, 0, numsSize - 1);
    uint32_t i = 0;
    int sum = 0;
    for (;i < numsSize; i+= 2)
        sum += nums[i];
//    printf("\n");
    return sum;
}
