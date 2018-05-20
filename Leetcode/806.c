//
//  806.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/19.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "806.h"
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
    uint32_t n = 0;
    static int re[2];
    int *line = &re[0];
    int *cnt = &re[1];
    for (; S[n] ;n++) {
        *cnt += widths[S[n] - 'a'];
        if (*cnt > 100)
            n--;
        if (*cnt >= 100) {
            *cnt = 0;
            (*line)++;
        }
    }
    *returnSize = 2;
    if (*cnt > 0)
        (*line)++;
    return re;
}
