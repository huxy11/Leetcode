//
//  heap.h
//  Leetcode
//
//  Created by 胡星宇 on 2020/1/11.
//  Copyright © 2020 胡星宇. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>
#include <stdlib.h>
typedef struct heap {
    int32_t is_max;
    size_t cnt;
    size_t size;
    int32_t* head;
}heap;

void heap_insert(heap*, const int32_t);
int32_t heap_drop(heap*);
int32_t heap_test(void);
heap* heap_create(size_t);
int32_t heap_destroy(heap** h);
static void heap_ascend(heap*, const size_t);
static void heap_desecnd(heap*);
#endif /* heap_h */
