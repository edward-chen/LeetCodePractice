//
//  BasicDataStructure.h
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/30.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef BasicDataStructure_h
#define BasicDataStructure_h

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

#endif /* BasicDataStructure_h */
