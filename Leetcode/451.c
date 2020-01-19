//
//  451.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/11/19.
//  Copyright © 2018 胡星宇. All rights reserved.
//

#include "451.h"
char* frequencySort(char* s)
{
    if (!s)
        return NULL;
    int32_t cnt[200] = {0, };
    int32_t n = 0;
    while (s[n]) {
        cnt[s[n++]]++;
        printf("%c cnt:%d\n", s[n-1], cnt[s[n-1]]);
    }
    char arr[100] = {0, };
    
    return NULL;
}
void ut_451(void)
{
    frequencySort("AaBbbbbcfd");
}
