//
//  C104MaxDepthOfBTree.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/25.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C104MaxDepthOfBTree_hpp
#define C104MaxDepthOfBTree_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

#include "CBinaryTree.hpp"

using namespace std;
using namespace BinaryTree;

namespace maxDepthOfBTree {
    class Solution {
    public:
        // 8ms (beats 9.13%)
        int maxDepth(TreeNode* root);
        // 8ms
        int maxDepthV2(TreeNode *root);
    };
    
}

#endif /* C104MaxDepthOfBTree_hpp */
