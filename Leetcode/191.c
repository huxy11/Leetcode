//
//  191.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/21.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "191.h"
int hammingWeight(uint32_t n) {
    uint32_t p;
    uint32_t sum = 0;
    while (n) {
        p = n & -n;
        n ^= p;
        sum++;
    }
    return sum;
}
