//
//  Stack.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/17.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "Stack.h"

stack* creatStack(size_t size)
{
    stack* re = malloc(sizeof(stack));
    re->base = malloc(size * sizeof(char*));
#ifdef DEBUG
    memset(re->base, 0, size * sizeof(char*));
#endif
    re->top = re->base;
    re->max = size;
    return re;
}

size_t sizeofStack(stack *s)
{
    return s->top - s->base;
}

void pushStack(void* input, stack* s)
{
    if(!input) {
        printf("Input is NULL!\n");
        return;
    }
    if (sizeofStack(s) == s->max) {
        printf("stack is full!\n");
        return;
    }
    *(s->top++) = input;
//    printf("%p %lu\n", *(s->top-1), **(int32_t**)(s->top-1));
    return;
}

void* popStack(stack* s)
{
    if (!sizeofStack(s)) {
        printf("stack is empty!\n");
        return NULL;
    }
    return *(--s->top);
}

void printStack(stack *s)
{
    char** p = (char**)(s->top - 1);
    for (;*p >= (char*)s->base; p--) {
        printf("%p %d\n", *p, **p);
    }
    return;
}

