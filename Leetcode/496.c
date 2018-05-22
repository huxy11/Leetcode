//
//  496.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "496.h"
static int findNGE(int n, int *nums, int numsSize)
{
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == n)
            break;
    }
    for (; i < numsSize; i++) {
        if (nums[i] > n)
            return nums[i];
    }
    return -1;
}
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
    *returnSize = findNumsSize;
    int* re = malloc(sizeof(int) * findNumsSize);
    uint32_t i;
    for (i = 0; i < findNumsSize; i++) {
        re[i] = findNGE(findNums[i], nums, numsSize);
    }
    return re;
}
