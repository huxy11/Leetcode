//
//  463.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "463.h"

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    uint32_t m,n;
//    char re[gridRowSize][gridColSize];
    for (m = 0;m < gridRowSize; m++)
        for(n = 0;n < gridColSize; n++) {
            if (grid[m][n] == 1) {
                if (m > 0 && grid[m-1][n] != 1)
                    grid[m-1][n] -= 1;
                if (m < gridRowSize - 1 && grid[m+1][n] != 1)
                    grid[m+1][n] -= 1;
                if (n > 0 && grid[m][n-1] != 1)
                    grid[m][n-1] -= 1;
                if (n < gridColSize - 1 && grid[m][n+1] != 1)
                    grid[m][n+1] -= 1;
            }
        }
    int32_t sum = 0;
    for (m = 0;m < gridRowSize; m++) {
        for(n = 0;n < gridColSize; n++) {
            if (grid[m][n] < 0)
                sum += grid[m][n];
        }
    }
    for (m = 0;m < gridRowSize; m++) {
        if (grid[m][0] == 1)
            sum--;
        if (grid[m][gridColSize - 1] == 1)
            sum--;
    }
    for(n = 0;n < gridColSize; n++) {
        if (grid[0][n] == 1)
            sum--;
        if (grid[gridRowSize- 1 ][n] == 1)
            sum--;
    }
    return -sum;
}
