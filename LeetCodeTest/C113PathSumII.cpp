//
//  C113PathSumII.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/18.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C113PathSumII.hpp"

using namespace BT_TreePathSum;

void Solution:: pathSumII (TreeNode *root, int sum, int currSum, vector<int> &currOutput, vector<vector<int>> &output) {
    
    if (root) {
        currOutput.push_back(root->val);
        currSum += root->val;
        pathSumII(root->left, sum, currSum, currOutput, output);
        pathSumII(root->right, sum, currSum, currOutput, output);
        
        if (sum == currSum && !root->left && !root->right) {
            output.push_back(currOutput);
        }
        currOutput.pop_back();
    }
}


vector<vector<int>> Solution::pathSum(TreeNode *root, int sum) {
    // 12ms (beats 79.96%)
    vector<vector<int>> output;
    vector<int> currOutput;
    
    if (root) {
        int nCurrSum = root->val;
        
        currOutput.push_back(root->val);
        pathSumII(root->left, sum, nCurrSum, currOutput, output);
        pathSumII(root->right, sum, nCurrSum, currOutput, output);
        
        if (nCurrSum == sum && !root->left && !root->right) {
            output.push_back(currOutput);
        }
    }
    

    return output;
}