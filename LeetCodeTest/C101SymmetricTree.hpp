//
//  C101SymmetricTree.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/11.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C101SymmetricTree_hpp
#define C101SymmetricTree_hpp

#include <stdio.h>
#include <queue>
#include <vector>

#include "BasicDataStructure.h"

using namespace std;

namespace BT_SymmetricTree {
    class Solution {
    private:
        int traversalInOrder(TreeNode *root, vector<int> &output);
    public:
        bool isSymmetric(TreeNode* root);
        bool isSymmetricRecursive(TreeNode *root);
    };
}

#endif /* C101SymmetricTree_hpp */
