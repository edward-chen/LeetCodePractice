//
//  C226InvertBinaryTree.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/7.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C226InvertBinaryTree.hpp"


using namespace BT_InvertBinaryTree;


TreeNode * Solution::invertTree(TreeNode* root) {
    // 0 ms (beats 7.97%)
    if (root) {
        std::swap(root->left, root->right);
    
        invertTree(root->left);
        invertTree(root->right);
    }
    
    return root;
}