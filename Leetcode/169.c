//
//  169.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/7/13.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "169.h"
int majorityElement(int* nums, int numsSize)
{
    int* a = malloc(10000*4);
    memset(a, 0, 10000*4);
    int32_t cnt = numsSize/2, i = 0;
    for (; i < numsSize; i++) {
        a[nums[i%10000]]++;
        if (a[nums[i%10000]] > cnt)
            return nums[i];
    }
    return -1;
}
