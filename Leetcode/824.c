//
//  824.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/20.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "824.h"

char* toGoatLatin(char* S) {
    char *str = malloc(2000);
    strcpy(str, S);
    char *word = strtok(str, " ");
    char *mod = malloc(2000);
    char *re = malloc(2000);
    char *cur = re;
    uint32_t sum = 1;
    do {
        uint32_t l;
        uint32_t len = (uint32_t)strlen(word);
        strcpy(mod, word);
        switch (mod[0]) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                l = 0;
                break;
            default:
                l = 1;
                mod[len] = mod[0];
        }
        mod[len + l] = 'm';
        int32_t i;
        for (i = 1; i <= sum + 1; i++)
            mod[len + l + i] = 'a';
        sum++;
        mod[len + l + i] = ' ';
        mod[len + l + i + 1] = 0;
        memcpy(cur, mod + l, strlen(mod + l));
        cur += strlen(mod + l);
    } while ((word = strtok(NULL, " ")));
    re[strlen(re) - 1] = 0;
    free(mod);
    return re;
}
