//
//  C103BinaryTreeZigzagLevelOrderTraversal.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/15.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C103BinaryTreeZigzagLevelOrderTraversal_hpp
#define C103BinaryTreeZigzagLevelOrderTraversal_hpp

#include <stdio.h>
#include "BasicDataStructure.h"

using namespace std;

namespace BT_BFS_Zigzag {
    class Solution {
    private:
        int push2Queue(queue<TreeNode *> &rTmpQ, TreeNode *pNode);
        int push2Stack(stack<TreeNode *> &rTmpS, TreeNode *pNode);
        
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root);
    };
}

#endif /* C103BinaryTreeZigzagLevelOrderTraversal_hpp */
