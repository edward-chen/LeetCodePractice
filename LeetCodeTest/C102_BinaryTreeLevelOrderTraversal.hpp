//
//  C102_BinaryTreeLevelOrderTraversal.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/15.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C102_BinaryTreeLevelOrderTraversal_hpp
#define C102_BinaryTreeLevelOrderTraversal_hpp

#include <stdio.h>
#include "BasicDataStructure.h"

using namespace std;

namespace BT_BFS {
    class Solution {
        
    public:
        vector<vector<int>> levelOrder(TreeNode *root);
    };
}


#endif /* C102_BinaryTreeLevelOrderTraversal_hpp */
