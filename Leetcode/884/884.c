//
//  884.c
//  Leetcode
//
//  Created by 胡星宇 on 2020/5/11.
//  Copyright © 2020 胡星宇. All rights reserved.
//


#include "884.h"
static void list_insert(ListNode** l, char *s) {
    while (*l) {
        if (strcmp((*l)->val, s) == 0) {
            (*l)->cnt++;
            return;
        }
        l = &((*l)->next);
    }
    (*l) = calloc(1, sizeof(ListNode));
    (*l)->cnt = 1;
    (*l)->next = NULL;
    (*l)->val = s;
}

char ** uncommonFromSentences(char * A, char * B, int* returnSize){
    ListNode* a = 0;
    ListNode* re = 0;
    *returnSize = 0;
    
    char *cur = strtok(A, " ");
    while (cur) {
        list_insert(&a, cur);
        cur = strtok(NULL, " ");
    }
    
    cur = strtok(B, " ");
    while (cur) {
        list_insert(&a, cur);
        cur = strtok(NULL, " ");
    }
    
    ListNode *crt = a;
    while (crt) {
        if (crt->cnt == 1) {
            list_insert(&re, crt->val);
            (*returnSize)++;
        }
        crt = crt->next;
    }
    char **ret = calloc(1, sizeof(char*[*returnSize]));
    for (int i = 0; i < *returnSize; ++i) {
        ret[i] = re->val;
        re = re->next;
    }
    return ret;
}
