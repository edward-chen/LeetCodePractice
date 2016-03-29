//
//  C092ReverseLinkedListII.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/30.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C092ReverseLinkedListII.hpp"


using namespace ReverseLinkedListII;


ListNode *Solution::reverseBetween(ListNode *head, int m, int n) {
    ListNode *pNode;
    
    
    
    return pNode;
}


Solution::Solution(unsigned int size) {
    printf("ctor (size: %d)=> ", size);
    m_nSize = size;
    m_pHead = NULL;
    for (unsigned int i = 0; i < size; i++) {
        ListNode *pNode = new ListNode(i);
        ListNode *pCurr;
        if (!m_pHead) {
            pCurr = m_pHead = pNode;
        } else {
            pCurr->next = pNode;
            pCurr = pNode;
        }
    }
    
    dumpList();
}

Solution::~Solution() {
    //printf("~ctor => ");
    while (m_pHead) {
        ListNode *pCurr = m_pHead;
        m_pHead = m_pHead->next;
        
        delete pCurr;
    }
    //dumpList();
}

void Solution::dumpList(ListNode *pNode, const char *pszMsg) {
    ListNode *pCurr = pNode;
    printf ("%s val: { ", pszMsg);
    while (pCurr) {
        if (pCurr->next) {
            printf("%d, ", pCurr->val);
        } else {
            printf("%d ", pCurr->val);
        }
        pCurr = pCurr->next;
    }
    
    printf("}\n");
}