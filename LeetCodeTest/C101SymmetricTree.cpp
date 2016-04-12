//
//  C101SymmetricTree.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/11.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C101SymmetricTree.hpp"


using namespace BT_SymmetricTree;

/* 
// ================================================
//   This is a typical symmetric tree
// ================================================
//       1
//      / \
//     2   2
//    / \ / \
//   3  4 4  3
//
// ================================================
//   This is not a symmetric tree
// ================================================
//       1
//      / \
//     2   2
//      \   \
//      3    3
//
*/

int Solution::traversalInOrder(TreeNode *root, vector<int> &output) {
    if (root) {
        traversalInOrder(root->left, output);
        if (!root->left && root->right) output.push_back(-1);
        output.push_back(root->val);
        if (root->left && !root->right) output.push_back(-1);
        traversalInOrder(root->right, output);
    }
    return (int) output.size();
}

bool Solution::isSymmetric(TreeNode *root) {
    bool bRet = true;
    vector <int> output;
    
    int size = traversalInOrder(root, output);
    do {
        if (!(size % 2)) {
            bRet = false;
            break;
        }
        
        int mid = size / 2;
        for (int i = 0; i < mid; i++) {
            if (output[i] != output[size - (i + 1)]) {
                bRet = false;
                break;
            }
        }
    } while (false);
    
    return bRet;
}

bool Solution::isSymmetricRecursive(TreeNode *root) {
    bool bRet = false;

    
    return bRet;
}