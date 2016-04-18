//
//  C257BinaryTreePath.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/18.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C257BinaryTreePath.hpp"

using namespace BT_Path;

void Solution::binaryTreePaths(TreeNode *root, string path, vector<string> &output) {
    string _path = path;
    
    if (root) {
        _path += "->" + std::to_string(root->val);
        binaryTreePaths(root->left, _path, output);
        binaryTreePaths(root->right, _path, output);
        
        if (!root->left && !root->right) {
            output.push_back(_path);
        }
    }
}

vector<string> Solution::binaryTreePaths(TreeNode *root) {
    // 4ms (beats 9.95%)
    vector<string> output;
    
    if (root) {
        string val = std::to_string(root->val) ;
        
        binaryTreePaths(root->left, val, output);
        binaryTreePaths(root->right, val, output);
    
        if (!root->left && !root->right) {
            output.push_back(val);
        }
    }

    return output;
}