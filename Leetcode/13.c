//
//  13.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/7/21.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "13.h"
int romanToInt(char* s)
{
    if (!s)
        return 0;
    int32_t n = strlen(s);
    int32_t i = 0, sum = 0;
    int32_t a['Z'] = {0,};
    a['I'] = 1;
    a['V'] = 5;
    a['X'] = 10;
    a['L'] = 50;
    a['C'] = 100;
    a['D'] = 500;
    a['M'] = 1000;
    for (;i < n; i++) {
        if (a[s[i]] < a[s[i+1]])
            sum -= a[s[i]];
        else
            sum += a[s[i]];
    }
    sum += a[s[n]];
    return sum;
}
