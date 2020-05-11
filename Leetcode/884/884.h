//
//  884.h
//  Leetcode
//
//  Created by 胡星宇 on 2020/5/11.
//  Copyright © 2020 胡星宇. All rights reserved.
//

#ifndef _84_h
#define _84_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct node {
    int cnt;
    char *val;
    struct node *next;
}ListNode;
char ** uncommonFromSentences(char * A, char * B, int* returnSize);

#endif /* _84_h */
