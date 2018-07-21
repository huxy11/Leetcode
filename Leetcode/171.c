//
//  171.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/7/13.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "171.h"

int titleToNumber(char* s)
{
    size_t len = strlen(s);
    size_t i = 0;
    char *str = malloc(len + 1);
    strcpy(str, s);
    uint32_t cnt = 0;
    for (; i < len; i++) {
        cnt += (uint32_t)(str[len - i - 1] - 'A' + 1) * pow(26, i);
    }
    return cnt;
}
