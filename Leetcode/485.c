//
//  485.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "485.h"

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int32_t pre = -1, cur = -1;
    int32_t max = 0;
    uint32_t i = 0;
    for (;i < numsSize; i++)
        if (!nums[i]) {
            cur = i;
            if ((cur - pre - 1) > max)
                max = cur - pre - 1;
            pre = cur;
        }
    if (cur == -1)
        return numsSize;
    if ((numsSize - cur - 1) > max)
        max = numsSize - cur - 1;
    return max;
}
