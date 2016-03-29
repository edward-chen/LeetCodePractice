//
//  C104MaxDepthOfBTree.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/25.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C104MaxDepthOfBTree.hpp"
#include <string.h>


using namespace maxDepthOfBTree;

int Solution::maxDepth(TreeNode* root) {
    int nLDepth = 1, nRDepth = 1;
    if (!root) {
        return 0;
    }
    
    if (!root->left) {
        nLDepth = 1;
    } else {
        nLDepth = maxDepth(root->left) + 1;
    }
    if (!root->right) {
        nRDepth = 1;
    } else {
        nRDepth = maxDepth(root->right) + 1;
    }
    return nRDepth > nLDepth? nRDepth: nLDepth;
}

int Solution::maxDepthV2(TreeNode *root) {
    int nLeftH = 0, nRightH = 0;
    
    if (root) {
        nLeftH = maxDepth(root->left) + 1;
        nRightH = maxDepth(root->right) + 1;
    } else {
        return 0;
    }
    
    return (nLeftH > nRightH) ? nLeftH: nRightH;
}
