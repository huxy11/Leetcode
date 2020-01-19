//
//  1046.c
//  Leetcode
//
//  Created by 胡星宇 on 2020/1/9.
//  Copyright © 2020 胡星宇. All rights reserved.
//

#include "1046.h"

int lastStoneWeight(int* stones, int stonesSize){
    int32_t i = 0;
    heap* h = heap_create(stonesSize);
    for (i = 0; i < stonesSize; ++i)
        heap_insert(h, stones[i]);
    while (h->cnt > 1) {
        int32_t a = heap_drop(h);
        int32_t b = heap_drop(h);
        int32_t c = a - b;
        if (c)
            heap_insert(h, c);
    }
    int32_t re;
    if (h->cnt == 0)
        re = 0;
    else
        re = heap_drop(h);
    return re;
}

void test_of_1046(void)
{
    int32_t a[] = {999, 999};
    int32_t size = sizeof(a)/sizeof(int32_t);
    printf("%d\n", lastStoneWeight(a, size));
    return;
}
