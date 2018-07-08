//
//  696.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/26.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "696.h"
int countBinarySubstrings(char* s) {
    int a = 0, b = 0;
    uint32_t cnt = 0;
    size_t i = 0;
    char c;
    while ((c = s[i])) {
        if (c == '0') {
            a++;
            if (b) {
                b--;
                cnt++;
                if (s[i + 1] == '1')
                    b = 0;
            }
        }
        if (c == '1') {
            b++;
            if (a) {
                a--;
                cnt++;
                if (s[i + 1] == '0')
                    a = 0;
            }
        }
        i++;
    }
    return cnt;
}
