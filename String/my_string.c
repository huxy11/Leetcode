//
//  my_string.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/4/25.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "my_string.h"

void test_string(void)
{
    
}

void *memchr(const void *str, int c, size_t n)
{
    const char* s = str;
    int i = 0;
    for (;i < n && s[i]; i++) {
        if (s[i] == c)
            return (char*)str + i;
    }
    return NULL;
}

