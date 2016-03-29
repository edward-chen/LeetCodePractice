//
//  C114BinaryTreePreorderTraversal.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C114BinaryTreePreorderTraversal.hpp"


using namespace BinaryTreePreorderTraversal;

void Solution::traversal(TreeNode *root, vector<int> &output) {
    if (root) {
        output.push_back(root->val);
        traversal(root->left, output);
        traversal(root->right, output);
    }
}