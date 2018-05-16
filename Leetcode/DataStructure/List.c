//
//  List.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/13.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "List.h"

list* creatList(const char* in)
{
    char *input = malloc(200);
    strcpy(input, in);
    if (*input++ != '[') {
        printf("Wrong input arguments!\n");
        return NULL;
    }
    list* head = malloc(sizeof(list));
    char *s = strtok(input, ",");
    list **cur;
    cur = &head;
    for(;s && ((*cur) = malloc(sizeof(list))); s = strtok(NULL, ",")) {
        (*cur)->val = atoi(s);
        cur = &(*cur)->next;
    }
    return head;
}
void printList(list* head)
{
    for (list *cur = head; cur; cur = cur->next)
        printf("%d->", cur->val);
        printf("\n");
}
void deleteList(list* head,int32_t val)
{
    list** cur, *fre;
    cur = &head;
    for (;*cur;) {
        if ((*cur)->val == val) {
            fre = *cur;
            *cur = (*cur)->next;
            free(fre);
        }
        else
            cur = &((*cur)->next);
    }
}
list* reverseList(list* head)
{
    if (!head)
        return NULL;
    list *pre, *cur, *post;
    pre = head;
    cur = pre->next;
    while (cur) {
        post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    head->next = NULL;
    return pre;
}

void test_List(void)
{
    list* l = creatList("[1,2,3,4,5]");
    deleteList(l, 3);
    printList(l);
    printList(reverseList(l));
    return;
}
