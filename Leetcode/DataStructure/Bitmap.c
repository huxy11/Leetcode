//
//  bit.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/15.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "Bitmap.h"
void printBinary(int32_t input)
{
    uint32_t mask = 1u << 31;
    uint32_t cnt = 1;
    printf("%d == ", input);
    for (;mask; mask >>= 1, cnt++)
        printf("%d%s", input & mask ? 1 : 0, (cnt % 4) ? "":" ");
    printf("\n");
    return;
}

uint32_t lowBit(uint32_t input)
{
    return input & - input;
}

void test_bitmap(void)
{
    uint32_t x = 0xaaaa;
    printBinary(x);
    printBinary(x ^ lowBit(x));
    printBinary(x & ~lowBit(x));
}
