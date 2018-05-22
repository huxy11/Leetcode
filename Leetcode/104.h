//
//  104.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef _04_h
#define _04_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int maxDepth(struct TreeNode* root);

#endif /* _04_h */
