//
//  461.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/18.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "461.h"

int hammingDistance(int x, int y) {
    
    int32_t re = x ^ y;
    uint32_t tmp = 1 << 31;
    uint32_t sum = 0;
    while (re) {
        tmp = re & -re;
        re ^= tmp;
        sum++;
    }
    return sum;
}

