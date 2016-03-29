//
//  C145BinaryTreePostorderTraversal.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C145BinaryTreePostorderTraversal_hpp
#define C145BinaryTreePostorderTraversal_hpp

#include <stdio.h>
#include "CBinaryTree.hpp"


using namespace BinaryTree;

namespace BinaryTreePostorderTraversal {
    class Solution {
    public:
        void traversal(TreeNode *root, vector<int> &output);
        vector <int> postorderTraversal(TreeNode *root) {
            vector <int> output;
            traversal(root, output);
            return output;
        }
    };
}

#endif /* C145BinaryTreePostorderTraversal_hpp */
