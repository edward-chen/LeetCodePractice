//
//  C112PathSum.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/18.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C112PathSum_hpp
#define C112PathSum_hpp

#include <stdio.h>
#include "BasicDataStructure.h"

using namespace std;

namespace BT_PathSum {
    class Solution {
    private:
        bool pathSum(TreeNode *root, int sum, int currSum);
    public:
        bool hasPathSum(TreeNode *root, int sum);
    };
}

#endif /* C112PathSum_hpp */
