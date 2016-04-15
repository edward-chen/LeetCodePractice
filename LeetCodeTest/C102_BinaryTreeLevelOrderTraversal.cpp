//
//  C102_BinaryTreeLevelOrderTraversal.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/15.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C102_BinaryTreeLevelOrderTraversal.hpp"

using namespace BT_BFS;

vector<vector<int>> Solution::levelOrder(TreeNode *root) {
    // 4 ms (beats 78.81%)
    vector <vector<int>> output;
    
    if (root) {
        queue<TreeNode *> tmpQ;
        vector<int> currOutput;
        tmpQ.push(root);
        int nodeCnt = 2;
        
        while (!tmpQ.empty()) {
            int times = nodeCnt / 2;
            int nextNodeCnt = 0;
            for(int i = 0; i < times; i++) {
                TreeNode *pNode = tmpQ.front();
                tmpQ.pop();
                
                currOutput.push_back(pNode->val);
                if (pNode->left) {
                    tmpQ.push(pNode->left);
                    nextNodeCnt += 2;
                }
                
                if (pNode->right) {
                    tmpQ.push(pNode->right);
                    nextNodeCnt += 2;
                }
            }
            
            nodeCnt = nextNodeCnt;
            output.push_back(currOutput);
            currOutput.clear();
        }
    
    }
    
    return output;
}
