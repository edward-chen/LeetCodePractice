//
//  C112PathSum.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/18.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C112PathSum.hpp"

using namespace BT_PathSum;
bool Solution:: pathSum(TreeNode *root, int sum, int currSum) {
    bool bRet = false;
    
    if (root) {
        currSum += root->val;
        
        do {
            if ((bRet = pathSum(root->left, sum, currSum)))
                break;
            if ((bRet = pathSum(root->right, sum, currSum)))
                break;
            
            if (sum == currSum && !root->left && !root->right){
                bRet = true;
            }
        } while (false);
    }
    
    return bRet;
}


bool Solution::hasPathSum(TreeNode *root, int sum) {
    // 12 ms (beats 10.02%)
    bool bRet = false;

    if (root) {
        int currSum = root->val;
        
        do {
            if ((bRet = pathSum(root->left, sum, currSum)))
                break;
            if ((bRet = pathSum(root->right, sum, currSum)))
                break;
            
            if (currSum == sum && !root->left && !root->right) {
                bRet = true;
            }
        } while (false);
    }
    
    return bRet;
}