//
//  695.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "695.h"
static int R;
static int C;
static void detect(int** grid, int i, int j, int* cnt) {
    (*cnt)++;
    grid[i][j] = 0;
    if (i > 0 && grid[i - 1][j])
        detect(grid, i - 1, j, cnt);
    if (i < R - 1 && grid[i + 1][j])
        detect(grid, i + 1, j, cnt);
    if (j > 0 && grid[i][j - 1])
        detect(grid, i, j - 1, cnt);
    if (j < C - 1 && grid[i][j + 1])
        detect(grid, i, j + 1, cnt);
}

int maxAreaOfIsland(int** grid, int gridRowSize, int gridColSize) {
    int re = 0, cnt = 0;
    uint32_t i, j;
    R = gridRowSize;
    C = gridColSize;
    for (i = 0; i < gridRowSize; i++)
        for (j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1) {
                detect(grid,i, j, &cnt);
                if (re < cnt)
                    re = cnt;
                cnt = 0;
            }
        }
    return re;
}
