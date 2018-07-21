//
//  860.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/7/11.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "860.h"

bool lemonadeChange(int* bills, int billsSize)
{
    int32_t sum_5 = 0;
    int32_t sum_10 = 0;
    uint32_t n = 0;
    for (;n <= billsSize; n++) {
        switch (bills[n]) {
        case 5:
            sum_5++;
            break;
        case 10:
            sum_5--;
            sum_10++;
            break;
        case 20:
            if (sum_10 > 0) {
                sum_10--;
                sum_5--;
            } else
                sum_5 -= 3;
            break;
        }
        if (sum_5 < 0)
            return false;
    }
    return true;
}
