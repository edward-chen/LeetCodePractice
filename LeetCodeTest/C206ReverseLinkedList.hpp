//
//  C206ReverseLinkedList.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C206ReverseLinkedList_hpp
#define C206ReverseLinkedList_hpp

#include <stdio.h>
#include "BasicDataStructure.h"



namespace ReverseLinkedList {
    class Solution {
    private:
        unsigned int m_nSize;
        ListNode *m_pHead;
        
        void dumpList() {
            dumpList(m_pHead, "(linked list)");
        }
        
        ListNode *reverseList(ListNode *head);
        ListNode *reverseList(ListNode *head, ListNode *pPrev);
        
    public:
        static const unsigned char OPT_ITERATIVE = 0;
        static const unsigned char OPT_RECURSIVE = 1;
        
        Solution(unsigned int size = 10);
        ~Solution();
        
        ListNode *reverseListFunc(ListNode *head, unsigned char opt);
        
        
        ListNode *getHead() { return m_pHead; }
        void setHead(ListNode *pNode) { m_pHead = pNode; }
        
        void dumpList(ListNode *pNode, const char *pszMsg);
    };
}
#endif /* C206ReverseLinkedList_hpp */
