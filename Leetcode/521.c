//
//  521.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "521.h"

int countPrimeSetBits(int L, int R) {
    const int p[] = {2,3,5,7,11,13,17,19,23,29,31};
    uint32_t sum = 0;
    while (L <= R) {
        uint32_t cnt = 0;
        uint32_t n = L;
        while (n) {
            n ^= n & -n;
            cnt++;
        }
        for (; n < 11; n++)
            if (cnt == p[n])
                sum++;
        L++;
    }
    return sum;
}


