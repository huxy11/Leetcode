//
//  206.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/14.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "206.h"

struct ListNode* reverseList1(struct ListNode* head) {
    if (!head)
        return NULL;
    struct ListNode *pre, *cur, *post;
    pre = head;
    if (head->next)
        cur = head->next;
    else
        return head;
    post = cur->next;
    pre ->next = NULL;
    for (;post; ) {
        cur->next = pre;
        pre = cur;
        cur = post;
        post = post->next;
    }
    cur->next = pre;
    return cur;
}

void test_206(void)
{
    list* head = creatList("[1]");
    head = reverseList1(head);
    printList(head);
}
