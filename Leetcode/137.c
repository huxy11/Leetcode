//
//  137.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/21.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "137.h"
int singleNumber2(int* nums, int numsSize)
{
    uint32_t a = 0;
    uint32_t b = 0;
    int32_t i = 0;
    for (; i < numsSize; i++) {
        uint32_t c = nums[i];
        uint32_t tmp = (a&~b&~c)|(~a&b&c);
        b = (~a&b&~c)|(~a&~b&c);
        a = tmp;
    }
    return b;
}
