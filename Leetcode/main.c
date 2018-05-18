//
//  main.c
//  Leetcode
//
//  Created by 胡星宇 on 2017/8/3.
//  Copyright © 2017年 胡星宇. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "List.h"
#include "Bitmap.h"
#include "queens.h"
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
#include "811.h"



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Test starts!\n");
    int* returnSize = 0;
    char* cpdomains[1];
    cpdomains[0] = malloc(24);
    strcpy(cpdomains[0], "9001 discuss.leetcode.com");
    subdomainVisits(cpdomains, 1, returnSize);
}
