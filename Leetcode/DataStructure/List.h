//
//  List.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/13.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    struct ListNode* next;
    int32_t val;
} list;

list* creatList(const char* input);
void printList(list* head);
void test_List(void);
void printIntStack(void);
list* reverseList(list* head);


#endif /* List_h */
