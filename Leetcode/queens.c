//
//  8queens.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/15.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "queens.h"
#include "bitmap.h"
uint32_t re = 0;

uint32_t queens(uint32_t n)
{
    int32_t *q = malloc(sizeof(uint32_t) * n);
    memset(q, 0xaa, sizeof(uint32_t) * n);
    printBinary(q[0]);
    int32_t row = 0, i;
    for (i = 0; i < n; i++) {
        row = 0;
        q[row++] = i;
        DFS(row, n, q);
    }
    printf("re = %d\n", re);
    return re;
}

void DFS(int32_t row, int32_t n, int32_t *q)
{
    int32_t i, j;
    for (i = 0; i < n; i++) {
        q[row] = i;
        for (j = 0; j < row; j++) {
            if (q[row] == q[j] || row - j == q[row] - q[j] || row - j == q[j] - q[row]) {
                q[row] = -1431655766;
                break;
            }
        }
        if (q[row] != -1431655766) {
            if (row == n - 1)
                re++;
            else
                DFS(row + 1, n, q);
        }
    }
}

void test_queens(void)
{
    queens(17);
}
