//
//  258.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "258.h"

int addDigits(int num) {
    int32_t cnt = 0;
    while (num / 10) {
        while (num) {
            cnt += num % 10;
            num /= 10;
        }
        num = cnt;
        cnt = 0;
    }
    return num;
}
