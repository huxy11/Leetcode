//
//  226.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/5/22.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef _26_h
#define _26_h

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* invertTree(struct TreeNode* root);

#endif /* _26_h */
