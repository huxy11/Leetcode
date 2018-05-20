//
//  811.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/18.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "811.h"

char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) {
    uint32_t n = 0;
    for (;n < cpdomainsSize; n++) {
        char* in = strchr(cpdomains[n], ' ') + 1;
        char* domain = strtok(cpdomains[n], " ");
        int32_t cnt = atoi(domain);
        while(in - 1)  {
            printf("%s:%d\n", in, cnt);
            in = strchr(in, '.') + 1;
        }
    }
    return NULL;
}


