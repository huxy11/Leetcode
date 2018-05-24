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
#include "389.h"

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
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void qs_modified(int *a, int* lo, int* hi, int* n)
{
    uint32_t m = 0;
    for (;m < *n; m++) {
        uint32_t i = lo[m];
        uint32_t j = hi[m];
        while (i < j) {
            while (i <= j && a[i] < a[j])
                i++;
            if (i < j)
                swap(&a[i++], &a[j]);
            while (i <= j && a[i] < a[j])
                j--;
            if (i < j)
                swap(&a[i], &a[j--]);
            if (j == hi[m])
                j--;
            if (i < hi[m]) {
                lo[++(*n)] = i;
                hi[*n] = hi[m];
            }
            if (j > lo[m]) {
                lo[++(*n)] = lo[m];
                hi[*n] = j;
            }
        }
    }
}

static void qs(int *a, size_t lo, size_t hi)
{
    if (lo >= hi)
        return;
    size_t m = lo - 1;
    size_t i = lo;
    //此处循环两个等号必须加上，才能保证a[m]是中间数。大于等于左边，小于右边。
    for (;i <= hi; i++) {
        if (a[i] <= a[hi])
            swap(&a[++m], &a[i]);
    }
    qs(a, lo, m - 1);
    qs(a, m + 1, hi);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Test starts!\n");
    printf("%c\n", findTheDifference("qwertyuiopsdfghjklzxcvbnm", "mnbvcxzsdfghjklpoiauytrewq"));
}
