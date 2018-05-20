//
//  344.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/19.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "344.h"
char* reverseString(char* s) {
    if (!s)
        return NULL;
    uint32_t len = (uint32_t)strlen(s);
    if (len == 0)
        return s;
    uint32_t i = 0;
    char tmp;
    len--;
    for (;i < len; i++, len--) {
        tmp = s[i];
        s[i] = s[len];
        s[len] = tmp;
    }
    return s;
}
