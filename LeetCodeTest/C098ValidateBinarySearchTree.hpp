//
//  C098ValidateBinarySearchTree.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/22.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C098ValidateBinarySearchTree_hpp
#define C098ValidateBinarySearchTree_hpp

#include <stdio.h>
#include "BasicDataStructure.h"

using namespace std;

namespace BT_ValidateBT {
    class node{
    public:
        int m_nVal;
        int m_nFromDir; //init: 0, left: 1, right: 2
        node(int val, int nDir) {
            m_nVal = val;
            m_nFromDir = nDir;
        }
        void setDir(int nDir) {
            m_nFromDir = nDir;
        }
    } ;
    
    class Solution{
    private:
        bool validForEachRoot(int val, vector<node> &rootVal);
        
    public:
        bool isValidBST(TreeNode* root, vector <node> &rootVal);
        bool isValidBST(TreeNode* root);
    };
}

#endif /* C098ValidateBinarySearchTree_hpp */
