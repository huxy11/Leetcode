//
//  985.c
//  Leetcode
//
//  Created by 胡星宇 on 2020/1/19.
//  Copyright © 2020 胡星宇. All rights reserved.
//

#include "985.h"
int32_t even_sum(int32_t* A, const int n, int32_t* flag)
{
    if (n < 1)
        return 0;
    int32_t i, sum = 0;
    for (i = 0; i < n; ++i) {
        if ((A[i] & 1) == 0){
            flag[i] = 1;
            sum += A[i];
        } else
            flag[i] = 0;
    }
    return sum;
}


int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    int32_t* re = 0;
    const int32_t n = ASize;
    const int32_t qn = queriesSize;
    re = malloc(qn * sizeof(int));
    int32_t* flag = malloc(n * sizeof(int32_t));
    int32_t i;
    int32_t sum = even_sum(A, n, flag);
    for (i = 0; i < qn; ++i) {
        int32_t index = queries[i][0];
        int32_t val = queries[i][1];
        
        if (flag[index]) {
            sum -= A[index];
        }
        
        A[index] += val;
        if ((A[index] & 1) == 0) {
            flag[i] = 1;
            sum += A[index];
        }
        else
            flag[i] = 0;
        
        re[i] = sum;
    }
    *returnSize = qn;
    return re;
}
int* sumEvenAfterQueries_bak(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    int32_t* re = 0;
    const int32_t n = ASize;
    
    const int32_t qn = queriesSize;
    re = malloc(qn * sizeof(int));
    int32_t i;
    for (i = 0; i < qn; ++i) {
        int32_t index = queries[i][0];
        int32_t val = queries[i][1];
        A[index] += val;
//        re[i] = even_sum(A, n);
    }
    *returnSize = qn;
    return re;
    
}

void test_of_evensum(int32_t r)
{
#define N 5
    int32_t a[N];
    int32_t i;
    srand(r);
    for (i = 0; i < N; ++i) {
        a[i] = rand() % (2 * N) - N + 1;
        printf("%d,%c", a[i], i == N - 1 ? '\n' : ' ');
    }
//    printf("even sum is :%d\n", even_sum(a, N));
}

void test_985(void)
{
    int32_t i;
    for (i = 0; i < 3; ++i)
        test_of_evensum(i);
    
}
