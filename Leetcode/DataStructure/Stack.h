//
//  Stack.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/17.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack {
    size_t max;
    void **top;
    void **base;
} stack;

stack* creatStack(size_t size);
size_t sizeofStack(stack *s);
void pushStack(void* input, stack* s);
void* popStack(stack* s);
void printStack(stack *s);




#endif /* Stack_h */
