//
//  C094BinaryTreeInorderTraversal.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C094BinaryTreeInorderTraversal.hpp"


using namespace BinaryTreeInorderTraversal;


void Solution::traversal(TreeNode *root, vector<int> &output) {
    if (root) {
        traversal(root->left, output);
        output.push_back(root->val);
        traversal(root->right, output);
    }
}