//
//  Queue.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/18.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    size_t max;
    void** head;
    void** rear;
}queue;
queue* creatQueue(size_t size);
void inQueue(void* input, queue* q);
void* outQueue(queue* q);
size_t sizeofQueue(queue* q);
void test_q(void);

#endif /* Queue_h */
