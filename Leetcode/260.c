//
//  260.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/21.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "260.h"

int* singleNumber3(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int32_t total = 0;
    uint32_t i = 0;
    for (; i < numsSize; i++)
        total ^= nums[i];
    total = total & -total; //low bit
    int *re = malloc(sizeof(int) * 2);
    re[0] = 0;
    re[1] = 0;
    for (i = 0; i < numsSize; i++)
        if (nums[i] & total)
            re[0] ^= nums[i];
        else
            re[1] ^= nums[i];
    return re;
}
