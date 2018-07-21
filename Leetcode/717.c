//
//  717.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/7/13.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "717.h"

bool isOneBitCharacter(int* bits, int bitsSize)
{
    uint32_t i = 0;
    for (;i < bitsSize - 1; i++) {
        if (bits[i] == 1)
            i++;
    }
    if (i == bitsSize)
        return false;
    else
        return true;
}
