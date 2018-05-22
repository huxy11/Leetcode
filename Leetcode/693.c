//
//  693.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "693.h"
#define ALT1 0xAAAAAAAA
#define ALT2 0x55555555
bool hasAlternatingBits(int n) {
    uint32_t mask = 0;
    int32_t a = n;
    while (a) {
        a = (uint32_t)a >> 1;
        mask <<= 1;
        mask++;
    }
    if (!(n ^ (mask & ALT1)) ||!(n ^ (mask & ALT2)))
        return true;
    return false;
}
