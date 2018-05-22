//
//  566.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "566.h"
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize)

{
    int32_t i;
    if (numsColSize * numsRowSize != r * c) {
        *returnSize = numsRowSize;
        *columnSizes = malloc(numsRowSize * sizeof(size_t));
        for ( i = 0; i < numsRowSize; i++) {
            (*columnSizes)[i] = numsColSize;
        }
        return nums;
    }
    int32_t n = r * c;
    int** re = malloc(r * sizeof(size_t));
    *columnSizes = malloc(r * sizeof(size_t));
    for (i = 0; i < r; i++) {
        re[i] = malloc(c * sizeof(size_t));
        (*columnSizes)[i] = c;
    }
    for (i = 0;i < n; i++) {
        re[i / c][i % c] = nums[i / numsColSize][i % numsColSize];
    }
    *returnSize = r;
    return re;
}
