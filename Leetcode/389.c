//
//  389.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/24.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "389.h"
static void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
static void qs(char *a, size_t lo, size_t hi)
{
    if ((int)lo >= (int)hi)
        return;
    size_t m = lo - 1;
    size_t i = lo;
    //此处循环两个等号必须加上，才能保证a[m]是中间数。大于等于左边，小于右边。
    for (;i <= hi; i++) {
        if (a[i] <= a[hi])
            swap(&a[++m], &a[i]);
    }
    qs(a, lo, m - 1);
    qs(a, m + 1, hi);
}


char findTheDifference(char* ss, char* tt) {
    if (!ss)
        return tt[0];
    size_t len = strlen(ss);
    char *s = malloc(len + 1);
    char *t = malloc(len + 2);
    strcpy(s, ss);
    strcpy(t, tt);
    qs(s, 0, len - 1);
    qs(t, 0, len);
    uint32_t i = 0;
    for (; i <= len; i++) {
//        printf("%c %c\n",s[i], t[i]);
        if (s[i] != t[i])
            return t[i];
    }
    return 0;
}
