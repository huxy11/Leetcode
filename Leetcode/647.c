//
//  647.c
//  Leetcode
//
//  Created by 胡星宇 on 2017/8/3.
//  Copyright © 2017年 胡星宇. All rights reserved.
//

#include "647.h"
#include <String.h>
int countSubstrings(char* s) {
    int n = (int)strlen(s);
    int a[n];
    a[0] = 1;
    int i = 1;
    for (;i < n; i++) {
        int j = 1;
        int cnt = 0;
        for (;j <= i; j++)
            if (isPalindromic(s, i - j, i))
                cnt++;
        a[i] = a[i - 1] + cnt + 1;
    }
    return a[n - 1];
}

int isPalindromic(char *s, int lo, int hi)
{
    int len = hi - lo + 1;
    int i;
    for (i = 0; i < len/2; i++)
        if (s[lo + i] != s[hi - i])
            return 0;
    return 1;
}
