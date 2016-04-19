//
//  C257BinaryTreePath.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/18.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C257BinaryTreePath_hpp
#define C257BinaryTreePath_hpp

#include <stdio.h>
#include <string>
#include "BasicDataStructure.h"

using namespace std;

namespace BT_Path {
    class Solution {
    private:
        void binaryTreePaths(TreeNode *root, string path, vector<string> &output);
    public:
        vector<string> binaryTreePaths(TreeNode* root);
    };
}


#endif /* C257BinaryTreePath_hpp */
