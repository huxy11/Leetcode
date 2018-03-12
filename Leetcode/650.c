//
//  650.c
//  Leetcode
//
//  Created by 胡星宇 on 2017/8/3.
//  Copyright © 2017年 胡星宇. All rights reserved.
//

#include "650.h"

#define MIN(x,y) x < y ? x : y

int minSteps(int n) {
    int a[n + 1];
    int i = 0;
    for (;i <= n;i++)
        a[i] = i;
    a[1] = 0;
    int j;
    for (i = 2; i <= n; i++)
        for (j = 1; j < i; j++)
            if (i % j == 0)
                a[i] = MIN(a[i], a[j] + i/j);
    return a[n];
}
