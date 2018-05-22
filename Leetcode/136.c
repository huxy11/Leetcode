//
//  136.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/21.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "136.h"

int singleNumber(int* nums, int numsSize) {
    uint32_t i = 0;
    int32_t re = 0;
    for (; i < numsSize; i++)
        re ^= nums[i];
    return re;
}
