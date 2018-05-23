//
//  796.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/23.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "796.h"
typedef struct stk {
    char val[150];
    int n;
}stk;

static void push(stk* s, const char c) {
    s->val[s->n] = c;
    s->n++;
}
static char pop(stk* s) {
    s->n--;
    return s->val[s->n];
}

bool rotateString(char* A, char* B) {
    stk s1;
    s1.n = 0;
    size_t na = 0,len = strlen(B), nb = len - 1;
    if (len != strlen(A))
        return false;
    while (na < len) {
        do
            push(&s1, A[na]);
        while (A[na++] != B[nb] && na < len);
        int n = s1.n;
        size_t m = nb;
        while (s1.n > 0) {
            char c = pop(&s1);
            if (c != B[nb--]) {
                s1.n = n;
                nb = m;
                break;
            }
        }
    }
    if (s1.n)
        return false;
    else
        return true;
}
