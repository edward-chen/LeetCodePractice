//
//  C111MinDepthOfBTree.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/28.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C111MinDepthOfBTree_hpp
#define C111MinDepthOfBTree_hpp

#include <stdio.h>
#include "CBinaryTree.hpp"
#include "C104MaxDepthOfBTree.hpp"

using namespace BinaryTree;

namespace minDepthOfBTree {
    class Solution {
    public:
        // 8ms (beats 9.13%)
        int minDepth(TreeNode* root);
    };
}


#endif /* C111MinDepthOfBTree_hpp */
