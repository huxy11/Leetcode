//
//  main.c
//  Leetcode
//
//  Created by 胡星宇 on 2017/8/3.
//  Copyright © 2017年 胡星宇. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "884/884.h"
//#include "QuickSort.h"


int main(int argc, const char * argv[]) {
    printf("Test starts!\n");
    char a[] = "this apple is sweet";
    char b[] = "this apple is sour";
    int retsize;
    char** ret = uncommonFromSentences(a, b, &retsize);
    printf("retsize = %d\n", retsize);
    for (int i =0 ; i < retsize; ++i)
        puts(ret[i]);
    
    
    printf("Test done!\n");
}
