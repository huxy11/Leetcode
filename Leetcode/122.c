//
//  122.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/11/17.
//  Copyright © 2018 胡星宇. All rights reserved.
//

#include "122.h"
int maxProfit(int* prices, int pricesSize)
{
    if (!prices)
        return 0;
    int32_t i, sum = 0;
    int32_t head = prices[0], tail = head;
    for (i = 0; i < pricesSize - 1; i++) {
        if (prices[i + 1] >= tail)
            tail = prices[i + 1];
        else {
            sum += tail - head;
            head = prices[i + 1];
            tail = head;
        }
    }
    if (tail > head)
        sum += tail - head;
    return sum;
}

void ut_122(void)
{
    int32_t a[] = {5,4,3,2,1};
    int32_t size = 5;
    printf("%d\n", maxProfit(a, size));
}
