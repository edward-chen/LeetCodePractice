//
//  C114BinaryTreePreorderTraversal.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C114BinaryTreePreorderTraversal_hpp
#define C114BinaryTreePreorderTraversal_hpp

#include <stdio.h>
#include "CBinaryTree.hpp"

using namespace BinaryTree;

namespace BinaryTreePreorderTraversal {
    class Solution {
        // 0 ~ 3ms (beats 10.97% ~  ??%)
    public:
        void traversal(TreeNode *root, vector <int> &output);
        vector<int> preorderTraversal(TreeNode* root) {
            vector <int> output;
            traversal(root, output);
            return output;
        }

    };
}
#endif /* C114BinaryTreePreorderTraversal_hpp */
