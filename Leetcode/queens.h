//
//  8queens.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/15.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef _queens_h
#define _queens_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t queens(uint32_t n);
void queens_test(void);
void DFS(int32_t row, int32_t n, int32_t* q);

#endif /* _queens_h */
