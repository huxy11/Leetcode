//
//  476.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/19.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "476.h"

int findComplement(int num) {
    int n = num;
    uint32_t mask = 0;
    while (n){
        mask <<= 1;
        mask += 1;
        n >>= 1;
    }
    return ~num & mask;
}
