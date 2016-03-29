//
//  C206ReverseLinkedList.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C206ReverseLinkedList.hpp"

using namespace ReverseLinkedList;

ListNode *Solution::reverseListFunc(ListNode *head, unsigned char opt) {
    ListNode *pNode = NULL;
    switch (opt) {
        case OPT_ITERATIVE:
            pNode = reverseList(head);
            break;
        case OPT_RECURSIVE:
            // TODO: need to implement it;
            pNode = reverseList(head, NULL);
            break;
        default:
            printf("!!unknown option: %d!!\n", opt);
            break;
    };
    
    return pNode;
}

ListNode *Solution::reverseList(ListNode *head, ListNode *pPrev) {
    // 8ms seconds (beats 13.13%)
    ListNode *pCurr = head;
    if (!pCurr) {
        return pCurr;
    }
    
    head = pCurr->next;
    pCurr->next = pPrev;
    
    return (head) ? reverseList(head, pCurr): pCurr;
}

ListNode *Solution::reverseList(ListNode *head) {
    // 8ms (beats 13.13%)
    ListNode *pCurr = NULL, *pPrev = NULL;
    if (!head) {
        return head;
    }
    
    while (head) {
        pCurr = head;
        head = pCurr->next;
        pCurr->next = pPrev;
        pPrev = pCurr;
    }
    
    //m_pHead = pCurr;
    return pCurr;
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