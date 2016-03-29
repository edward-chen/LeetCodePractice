//
//  C111MinDepthOfBTree.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/28.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C111MinDepthOfBTree.hpp"
#include "C104MaxDepthOfBTree.hpp"

using namespace minDepthOfBTree;

int Solution::minDepth(TreeNode* root) {
    int nLDepth = 0, nRDepth = 0, nDepth = 0;
    if (root) {
        nLDepth = minDepth(root->left) + 1;
        nRDepth = minDepth(root->right) + 1;
        
        if (nLDepth != nRDepth) {
            if (nLDepth == 1) {
                // means Left is NULL, use right depth
                return nRDepth;
            } else if (nRDepth == 1) {
                // means Right i NULL, use left depth
                return nLDepth;
            } else {
                // return smaller if both left and right not null
                return (nLDepth > nRDepth) ? nRDepth: nLDepth;
            }
        } else {
            // same Depth,
            return nLDepth;
        }
    }
    
    // root is null, return 0;
    return nDepth;
}