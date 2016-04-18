//
//  C113PathSumII.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/18.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C113PathSumII_hpp
#define C113PathSumII_hpp

#include <stdio.h>
#include "BasicDataStructure.h"

using namespace std;

namespace BT_TreePathSum {
    class Solution {
    private:
        void pathSumII(TreeNode *root, int sum, int currSum, vector<int> &currOutput, vector<vector<int>> &output);
    public:
        vector<vector<int>> pathSum(TreeNode *root, int sum);
    };
}

#endif /* C113PathSumII_hpp */
