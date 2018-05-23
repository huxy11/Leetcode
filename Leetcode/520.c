//
//  520.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "520.h"

bool detectCapitalUse(char* word) {
    uint32_t i = 1;
    uint32_t mask = 1 << 5;
    uint32_t sum1 = 0xFFFFFFFF;
    uint32_t sum2 = 0;
    size_t len = strlen(word);
    for (; i < len; i++) {
        sum1 &= word[i];
        sum2 |= word[i];
    }
    if (sum1 & mask)
        return true;
    if (!(sum2 & mask))
        if (!(word[0] & mask))
            return true;
    return false;
}
