//
//  832.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/17.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef _32_h
#define _32_h

#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize)
{
    uint32_t row = ARowSize;
    uint32_t col = row;
    uint32_t i, j;
    columnSizes = malloc(sizeof(int) * row * row);
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++)
            columnSizes[i][j] = col;
    }
    *returnSize = row;
    return A;
}

#endif /* _32_h */
