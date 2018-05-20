//
//  657.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/18.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "657.h"

bool judgeCircle(char* moves)
{
    static int col[86];
    static int row[86];
//    printf("U:%d, D:%d L:%d, R:%d\n", 'U','D','L','R');
    col['U'] = 1; col['D'] = -1;
    row['L'] = 1; row['R'] = -1;
    uint32_t n = 0;
    int32_t a = 0 ,b = 0;
    size_t len = strlen(moves);
    for (;n < len; n++) {
        a += col[moves[n]];
        b += row[moves[n]];
    }
    if (!a && !b)
        return true;
    else
        return false;
}
