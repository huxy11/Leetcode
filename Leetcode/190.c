//
//  190.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/21.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "190.h"

uint32_t reverseBits(uint32_t n) {
    uint32_t lmask = 1;
    uint32_t rmask = 1;
    lmask <<= 31;
    uint32_t i = 0;
    for (; i < 16; i++) {
        uint32_t tmp = n;
        if (tmp & lmask)
            n |= rmask;
        else
            n &= ~rmask;
        if (tmp & rmask)
            n |= lmask;
        else
            n &= ~lmask;
        rmask <<= 1;
        lmask >>= 1;
    }
    return n;
}
