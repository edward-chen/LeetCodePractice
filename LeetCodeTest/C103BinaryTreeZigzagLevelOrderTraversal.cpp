//
//  C103BinaryTreeZigzagLevelOrderTraversal.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/15.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C103BinaryTreeZigzagLevelOrderTraversal.hpp"

using namespace BT_BFS_Zigzag;

int Solution::push2Queue(queue<TreeNode *> &rTmpQ, TreeNode *pNode) {
    int cnt = 0;
    if (pNode) {
        rTmpQ.push(pNode);
        cnt = 2;
    }
    
    return cnt;
}

int Solution::push2Stack(stack<TreeNode *> &rTmpS, TreeNode *pNode) {
    int cnt = 0;
    if (pNode) {
        rTmpS.push(pNode);
        cnt = 2;
    }
    
    return 2;
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root) {
    // 4ms (beats 6.51%)
    vector<vector<int>> output;
    vector<int> currOutput;
    queue<TreeNode *> tmpQ;

    int nodeCnt = 2;
    bool bR2L = true;
    if (root) {
        tmpQ.push(root);
        while (!tmpQ.empty()) {
            int times = nodeCnt / 2;
            nodeCnt = 0;
            
            for(int i = 0; i < times; i++) {
                TreeNode *pNode = tmpQ.front();
                tmpQ.pop();
                
                nodeCnt += push2Queue(tmpQ, pNode->left);
                nodeCnt += push2Queue(tmpQ, pNode->right);
                currOutput.push_back(pNode->val);
            }
            
            
            if (!bR2L) {
                bR2L = true;
                std::reverse(currOutput.rbegin(), currOutput.rend());
            } else {
                bR2L = false;
            }
            
            output.push_back(currOutput);
            currOutput.clear();
        }
    }
    
    return output;
}