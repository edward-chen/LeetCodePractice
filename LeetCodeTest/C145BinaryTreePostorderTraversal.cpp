//
//  C145BinaryTreePostorderTraversal.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C145BinaryTreePostorderTraversal.hpp"

using namespace BinaryTreePostorderTraversal;

void Solution::traversal(TreeNode *root, vector<int> &output) {
    if (root) {
        traversal(root->left, output);
        traversal(root->right, output);
        output.push_back(root->val);
    }
}