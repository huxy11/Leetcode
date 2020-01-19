//
//  main.c
//  Leetcode
//
//  Created by 胡星宇 on 2017/8/3.
//  Copyright © 2017年 胡星宇. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "List.h"
#include "Bitmap.h"
#include "queens.h"
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
#include "heap.h"
#include "QuickSort.h"
#include "1046.h"

static int fb_tail(int* a, int* n)
{
    if (a[*n] == 1 || a[*n] == 2) {
        if (*n == 1)
            return 0;
        if (a[*n] == 2) {
            a[++(*n)] = 1;
        }
        int32_t i = 0;
        a[*n] = 0;
        a[*n - 1] = 1;
        for (i = *n - 2; i >= 0; i--)
            a[i] = a[i + 1] + a[i + 2];
        return a[0];
    }
    a[*n + 1] = a[*n] - 1;
    a[*n + 2] = a[*n] - 2;
    *n += 2;
    return fb_tail(a, n);
}
static int fb(int a)
{
    if (a == 1)
        return 0;
    if (a == 2)
        return 1;
    return fb(a - 1) + fb(a - 2);
}
static void swap(int* a, int* b)
{
    if (!a | !b)
        printf("%s is empty!\n", a ? "B" : "A");
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void quick_sort_new(int* a, int32_t lo, int32_t hi)
{
    if (lo >= hi)
        return;
    int32_t i = lo - 1, j = lo;
    for (; j <= hi; ++j) {
        if (a[j] <= a[hi]) {
            swap(&a[++i], &a[j]);
        }
    }
    //swap(&a[++i], &a[hi]);
    if (lo < i - 1)
        quick_sort_new(a, lo, i - 1);
    if (hi > i + 1)
        quick_sort_new(a, i + 1, hi);
}
static void quick_s(int32_t *a, size_t lo, size_t hi)
{
    if (lo <= hi)
        return;
    
}

static void quick_sort(int32_t *a, size_t lo, size_t hi)
{
    if (lo <= hi)
        return;
    size_t i = lo - 1;
    size_t j = lo;
    for (; j <= hi; ++j) {
        if (a[hi] <= a[j])
            swap(&a[++i], &a[j]);
    }
    quick_sort(a, lo, i - 1);
    quick_sort(a, i + 1, lo);
}

static void qs(int *a, size_t lo, size_t hi)
{
    if (lo >= hi)
        return;
    size_t m = lo - 1;
    size_t i = lo;
    //此处循环两个等号必须加上，可在最后一个循环把a[hi]swap至分割点
    for (;i <= hi; i++) {
        if (a[i] <= a[hi])
            swap(&a[++m], &a[i]);
    }
    qs(a, lo, m - 1);
    qs(a, m + 1, hi);
}

int portion(int32_t* a, int32_t p, int32_t q) {
    int32_t i, j;
    int32_t s = a[q];
    int32_t t;
    for (i = p - 1, j = p; j < q; j++) {
        if (a[j] <= s) {
            i++;
            int32_t temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        
        for (t = p; t <= q; t++)
            printf("%d\t", a[t]);
        printf("\n");
    }
    
    int32_t temp = a[q];
    a[q] = a[i + 1];
    a[i + 1] = temp;
    for (t = p; t <= q; t++)
        printf("%d\t", a[t]);
    printf("\n");
    return i + 1;
}

void qqqsss(int32_t* a, int32_t x, int32_t y) {
    if (x >= y)
        return;
    else {
        int32_t mid = portion(a, x, y);
        qqqsss(a, x, mid - 1);
        qqqsss(a, mid + 1, y);
        return;
    }
}
void foo(const int *a)
{
    printf("%d\n", *a);
}

int main(int argc, const char * argv[]) {
    printf("Test starts!\n");
    test_of_QuickSort(argc, argv);
    printf("Test done!\n");
}
