//
//  heap.c
//  Leetcode
//
//  Created by 胡星宇 on 2020/1/11.
//  Copyright © 2020 胡星宇. All rights reserved.
//
#include "heap.h"

#define H(x) h->head[x]
static void heap_swap(heap* h, size_t a, size_t b)
{
    int32_t tmp = H(a);
    H(a) = H(b);
    H(b) = tmp;
}
static void heap_print(heap* h)
{
    int32_t i, k;
    int32_t j = 1;
    size_t n = h->cnt >> 1;
    for (i = 1; i <= h->cnt; ) {
        for (k = 0; k < n; ++k)
            printf(" ");
        for (;i <= j && i <=h->cnt; ++i)
            printf(" [%d]%d ", i, H(i));
        putchar('\n');
        j = 2 * j + 1;
        n = n >>1;
    }
    putchar('\n');
}

heap* heap_create(size_t size)
{
    heap* h = malloc(sizeof(heap));
    h->cnt = 0;
    h->size = size;
    h->head = malloc(sizeof(int32_t)*(size+1));
    h->is_max = 1;
    return h;
}
int32_t heap_destroy(heap** h)
{
    if (!h)
        return 1;
    if((*h)->head)
        free((*h)->head);
    free(*h);
    *h = 0;
    return 0;
}

void heap_ascend(heap* h, const size_t index)
{
    
    if (!h) {
        printf("null pointer!\n");
        return;
    }
    if (h->cnt < index) {
        printf("invalid index!\n");
        return;
    }
    size_t cur = index;
    while (cur > 1 ) {
        if (H(cur) > H(cur / 2)) {
            heap_swap(h, cur, cur / 2);
            cur = cur / 2;
        } else
            break;
    }
}
void heap_descend(heap* h)
{
    if (!h) {
        printf("null pointer!\n");
        return;
    }
    if (h->cnt == 0) {
        printf("heap is empty!\n");
        return;
    }
    size_t cur = 1;
    while (cur <= h->cnt/2) {
        size_t max = 2 * cur;
        if  ((max + 1 <= h->cnt) && (H(max+1) > H(max)))
            ++max;
        if (H(cur) < H(max)) {
            heap_swap(h, cur, max);
            cur = max;
        } else
            break;
    }
}
void heap_insert(heap* h, const int32_t v)
{
    if (!h) {
        printf("null pointer!\n");
        return;
    }
    if (h->cnt == h->size) {
        printf("heap is full!\n");
        return;
    }
    
    h->cnt++;
    H(h->cnt) = v;
    heap_ascend(h, h->cnt);
}
int32_t heap_drop(heap* h) {
    if (!h) {
        printf("null pointer!\n");
        return 0;
    }
    if (h->cnt == 0) {
        printf("heap is empty!\n");
        return 0;
    }
    int32_t re = H(1);
    if (h->cnt == 1) {
        h->cnt--;
        return re;
    }
    H(1) = H(h->cnt--);
    heap_descend(h);
    return re;
}

int32_t heap_test(void)
{
    printf("heap test initiating...\n");
    heap* h = heap_create(10);
    if (h)
        printf("heap has been created!\n");
    heap_destroy(&h);
    
#define N 12
    int32_t i;
    h = heap_create(N);
    for (i = 1; i <= N; ++i) {
        heap_insert(h, rand() % 31 - 15);
    }
    heap_print(h);
    
    H(1) = -30;
    heap_descend(h);
    heap_print(h);
    
    for (i = 1; i <= N; ++i) {
        printf("[%d]%d%c", i, heap_drop(h),i == N ? '\n' : ' ');
    }
    
    heap_destroy(&h);
    if (!h)
        printf("heap has been destroyed!\n");
    return 0;
    
}
