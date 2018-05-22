//
//  766.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "766.h"

bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int32_t a;
    int32_t i, m ,n;
    for (i = 0; i < matrixRowSize; i++)
        for (a = matrix[i][0], m = i, n = 0; m < matrixRowSize && n < matrixColSizes[0]; m++, n++)
            if (a != matrix[m][n])
                return false;
    for (i = 0; i < matrixColSizes[0]; i++)
        for (a = matrix[0][i], m = 0, n = i; m < matrixRowSize && n < matrixColSizes[0]; m++,n++)
            if (a != matrix[m][n])
                return false;
    return true;
}
