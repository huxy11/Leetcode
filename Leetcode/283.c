//
//  283.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "283.h"

void moveZeroes(int* nums, int numsSize) {
    uint32_t l = 0, r = 0;
    for (;r < numsSize; r++)
        if (!nums[r]) {
            l = r++;
            break;
        }
    for (;r < numsSize;) {
        if (nums[r]) {
            nums[l++] =nums[r];
            nums[r++] = 0;
        } else
            r++;
    }
}
