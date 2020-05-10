//
//  867.c
//  Leetcode
//
//  Created by 胡星宇 on 2020/5/9.
//  Copyright © 2020 胡星宇. All rights reserved.
//

#include "867.h"

int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int r = ASize, c = AColSize[0];
    int *cs = calloc(1, sizeof (int[c]));
    int** a = calloc(1, sizeof(int*[c]));
    for (int i = 0; i < c; ++i) {
        a[i] = calloc(1, sizeof(int[r]));
        cs[i] = r;
        for (int j = 0;  j < r; ++j)
            a[i][j] = A[j][i];
    }
    *returnSize = c;
    *returnColumnSizes = cs;
    return a;
}
