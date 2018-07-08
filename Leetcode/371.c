//
//  371.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/26.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "371.h"

int getSum(int a, int b) {
    int c = (a & b) << 1;
    int d = a ^ b;
    while (c) {
        int nc = (d & c) << 1;
        d ^= c;
        c = nc;
    }
    return d;
}
