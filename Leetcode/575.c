//
//  575.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "575.h"

int distributeCandies(int* candies, int candiesSize) {
    int arr[200001] = {};
    int *a = arr + 100000;
    uint32_t cnt = 0, n = candiesSize/2;
    int32_t i = 0;
    for (;cnt < n && i < candiesSize; i++){
        if (!a[candies[i]]) {
            a[candies[i]] = 1;
            cnt++;
        }
    }
    return cnt;
}
