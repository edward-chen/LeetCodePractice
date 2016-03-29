//
//  C094BinaryTreeInorderTraversal.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C094BinaryTreeInorderTraversal_hpp
#define C094BinaryTreeInorderTraversal_hpp

#include <stdio.h>
#include "CBinaryTree.hpp"

using namespace BinaryTree;

namespace BinaryTreeInorderTraversal {
    class Solution {
    public:
        vector <int> inorderTraversal(TreeNode *root) {
            vector<int> output;
            traversal(root, output);
            
            return output;
        }
        
        void traversal(TreeNode *root, vector<int> &output);
    };
}

#endif /* C094BinaryTreeInorderTraversal_hpp */
