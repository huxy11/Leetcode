//
//  788.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/26.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "788.h"

int rotatedDigits(int N) {
    int a[N + 1];
    memset(a, 0xFFFFFFFF, N+1);
    a[0] = 0;
    uint32_t i;
    uint32_t cnt = 0;
    for (i = 1; i <= N; i++) {
        int r = i % 10;
        int l = i / 10;
        if (a[l] != -1) {
            switch (r) {
                case 2:
                case 5:
                case 6:
                case 9:
                    a[i] = 1;
                    cnt++;
                    printf("%d\n", i);
                    break;
                case 1:
                case 0:
                case 8:
                    if (a[l]) {
                        cnt++;
                        printf("%d\n", i);
                        a[i] = 1;
                    } else
                        a[i] = 0;
                    break;
                default:
                    a[i] = -1;
                    break;
            }
        }
    }
    return cnt;
}
