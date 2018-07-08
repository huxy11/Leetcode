//
//  BST.h
//  Leetcode
//
//  Created by 胡星宇 on 2018/3/18.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <stdio.h>
#include "BinaryTree.h"

int32_t isBST(TreeNode* root);
TreeNode* minBST(TreeNode* root);
TreeNode* maxBST(TreeNode* root);
TreeNode* findBST(TreeNode* root, int32_t val);
void test_BST(void);

#endif /* BST_h */
