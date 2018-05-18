//
//  804.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/17.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "804.h"
char* m[]= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int uniqueMorseRepresentations(char** words, int wordsSize) {
    int32_t n = wordsSize;
    int32_t i = 0;
    char *result[100];
    uint32_t sum = 0;
    for (; i < n; i++) {
        char *re = malloc(80);
        transformation(words[i], &re);
        int32_t j = 0;
        char flag = 0;
        for (; j < sum; j++) {
            if (!strcmp(result[j], re)) {
                flag = 1;
                break;
            }
        }
        if (flag)
            flag = 0;
        else {
            result[sum] = malloc(80);
            strcpy(result[sum++], re);
        }
        memset(re, 0, 80);
        free(re);
    }
    for (i = 0; i < sum; i++) {
        memset(result[i], 0, 80);
        free(result[i]);
    }
    return sum;
}

void transformation(const char *word, char** re)
{
    int32_t i = 0;
    memset(*re, 0, 80);
    for (;i < strlen(word); i++) {
        strcat(*re, m[word[i] - 'a']);
    }
    printf("%s\n", *re);
}
