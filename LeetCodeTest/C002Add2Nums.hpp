//
//  C002Add2Nums.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/10.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C002Add2Nums_hpp
#define C002Add2Nums_hpp

#include <stdio.h>
#include "BasicDataStructure.h"

namespace add2nums {
    class Solution {
    private:
        int m_nVer;
        static const int VER_MIN = 1;
        static const int VER_MAX = 2;
        static const int VER_ERR = -1;
    public:
        Solution(int ver);
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
        ListNode* addTwoNumbers_ver1(ListNode* l1, ListNode* l2);
        ListNode* addTwoNumbers_ver2(ListNode* l1, ListNode* l2);
    };
    
    class CTestGen {
    public:
        ListNode *initList(const int *pArray, int arraySize);
        void freeList(ListNode *pListNode);
        void dumpList(const ListNode *pListNode);
    };
}
#endif /* C002Add2Nums_hpp */
