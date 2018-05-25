//
//  448.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/25.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "448.h"

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    size_t i;
    for (i = 0; i < numsSize; i++) {
        size_t m = abs(nums[i]) - 1;
        if (nums[m] > 0) {
            nums[m] = -nums[m];
            (*returnSize)--;
        }
    }
    int* re = malloc(*returnSize * sizeof(int));
    size_t cnt = 0;
    for (i = 0; i < numsSize; i++)
        if (nums[i] > 0)
            re[cnt++] = (int)i + 1;
    printf("%d\n", *returnSize);
    return re;
}
