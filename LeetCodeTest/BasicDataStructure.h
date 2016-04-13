//
//  BasicDataStructure.h
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/30.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef BasicDataStructure_h
#define BasicDataStructure_h

#include <vector>
#include <queue>
#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


enum USING_FUNC_OPT{
    E_ITERATIVE = 0,
    E_RECURSIVE,
    E_DP,           // Dynamic programming
};
#endif /* BasicDataStructure_h */
