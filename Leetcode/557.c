//
//  557.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/19.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "557.h"
static void reverse(char* s,int32_t l, int32_t r)
{
    char tmp;
    
    for(;l < r;l++, r--) {
        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
    }
}

char* reverseWords(char* s)
{
    int32_t len = (int32_t)strlen(s);
    int32_t r = 0, l = 0;
    for (;r < len; r++) {
        if (s[r] == ' ') {
            reverse(s, l, r - 1);
            l = r + 1;
        }
    }
    if (l < r)
        reverse(s, l, r - 1);
    return s;
}
