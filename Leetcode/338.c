//
//  338.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/21.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "338.h"

int* countBits(int num, int* returnSize) {
    int* re = malloc((num +1)  *sizeof(int));
    uint32_t i = 1;
    re[0] = 0;
    for (; i <= num; i++) {
        re[i] = re[i >> 1] + (i & 1);
    }
    *returnSize = num + 1;
    return re;
}
