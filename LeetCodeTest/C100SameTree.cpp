//
//  C100SameTree.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/7.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C100SameTree.hpp"

using namespace BT_SameTree;

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
    // 0 ms (beats 4.84%)
    bool bRet = true;
    
    if (p && q) {
        do {
            if (p->val == q->val) {
                if (false == (bRet = isSameTree(p->left, q->left)))
                    break;
                if (false == (bRet = isSameTree(p->right, q->right)))
                    break;
            } else {
                bRet = false;
            }
        } while (false);
                
    } else {
        if (p || q){
            bRet = false;
        }
        
    }
    

    return bRet;
}