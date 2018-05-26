//
//  QuickSort.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/25.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "QuickSort.h"
static void* tmp;
static void swap(void* a, void* b, size_t size)
{
    if(!tmp)
        tmp = malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

void quickSort(void *a, const size_t size, const size_t lo, const size_t hi)
{
    if (lo >= hi)
        return;
    size_t m = lo - 1;
    size_t i = lo;
    for (; i <= hi; i++) {
        if (strcmp((char*)(a + i * size), (char*)(a + hi * size)) <= 0) {
            printf("%d\n", ((int*)a)[i]);
            swap(a + ++m * size, a + i * size, size);
            printf("%d %d\n", ((int*)a)[m], ((int*)a)[i]);
        }
    }
    if ((int64_t)lo < (int64_t)m - 1)
        quickSort(a, size, lo, m - 1);
    if ((int64_t)hi > (int64_t)m + 1)
        quickSort(a, size, m + 1, hi);
}

static int main(int argc, const char* argv[])
{
    int a[] = {9,99,99,99,2,3,4,4,4,2,1};
    int len = sizeof(a)/sizeof(int);
    quickSort(a, 4, 0, len - 1);
//    swap(&a[0], &a[1], 4);
    for (int i = 0; i < len; i++)
        printf("%d  ", a[i]);
    printf("\n");

}
