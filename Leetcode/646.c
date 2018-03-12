//
//  646.c
//  Leetcode
//
//  Created by 胡星宇 on 2017/8/3.
//  Copyright © 2017年 胡星宇. All rights reserved.
//

#include "646.h"
void swap(int32_t **a, int32_t x, int32_t y)
{
    int32_t temp = a[x][0];
    a[x][0] = a[y][0];
    a[y][0] = temp;
    
    temp = a[x][1];
    a[x][1] = a[y][1];
    a[y][1] = temp;
}

void quick_sort(int32_t **a, int32_t lo, int32_t hi)
{
    int32_t i = lo + 1;
    int32_t j = hi;
    while (1) {
        while (i < hi && a[i][0] < a[lo][0])
            i++;
        while (j > lo && a[j][0] > a[lo][0])
            j--;
        if (i < j)
            swap(a, i++, j--);
        else
            break;
    }
    if (j > lo) {
        swap(a, lo, j);
        if (j == i) {
            if (j > 0)
                j--;
            else
                i++;
        }
        
    }
    if (lo < j)
        quick_sort(a, lo, j);
    if (hi > i)
        quick_sort(a, i, hi);
}

int findLongestChain(int** pairs, int pairsRowSize, int pairsColSize) {
#define MAX(x,y) x > y ? x : y
    int n = pairsRowSize;
    quick_sort(pairs, 0, n - 1);
    int i = 1;
    int a[n];
    a[0] = 1;
    for (; i < n; i++) {
        a[i] = a[i - 1];
        int j = 0;
        for (; j < i; j++)
            if (pairs[j][1] < pairs[i][0])
                a[i] = MAX(a[i], a[j] + 1);
    }
    return a[n - 1];
}


void test_646() {
    // insert code here...
    printf("Hello, World!\n");
    int a[5][2] = {{9,10},{-4,9},{-5,6},{-5,9},{8,9}};
    int *p[5];
    int i;
    for (i = 0; i < 5; i++)
        p[i] = a[i];

    printf("%d\n",findLongestChain(p, 5, 2));
   
}
