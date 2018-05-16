//
//  BinaryTree.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/12.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* creatTree(const char* in);
TreeNode* creatTreeNode(int32_t val);
void freeTree(TreeNode* root);
//TreeNode* creatBST(const char* in);

void printTreePre(TreeNode *root);
void printTreeMid(TreeNode *root);
void printTreePost(TreeNode *root);
void test_bt(void);


#endif /* BinaryTree_h */
