//
//  C092ReverseLinkedListII.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/30.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C092ReverseLinkedListII.hpp"


using namespace ReverseLinkedListII;

ListNode *Solution::reverseBetweenFunc(ListNode *head, int m, int n, unsigned char opt) {
    ListNode *pNode = NULL;
    switch (opt) {
        case E_ITERATIVE:
            pNode = reverseBetween(head, m, n);
            break;
        case E_RECURSIVE:
            // TODO: need to implement here
            pNode = reverseBetweenRecursive(head, m, n);
            break;
        default:
            printf("!!unknown function option: %d\n", opt);
            break;
    };
    
    return pNode;
}

ListNode *Solution::reverseBetweenRecursive(ListNode *head, int m, int n) {
    // 0 ms ~ 4ms (breats 89.68% ~ 2.02%)
    ListNode *pCurr = head;
    ListNode *pPrev = NULL;
    ListNode *pTail = NULL;
    int count = n - m;
    if (m == n) {
        return pCurr;
    }
    
    for (int i = 1; i < m; i++) {
        pPrev = pCurr;
        pCurr = pCurr->next;
    }
    
    //pPreRevHead = pCurr;
    ListNode *pRevTail = reverseBetweenRecursive(pCurr->next, pCurr, &pTail, --count);
    pCurr->next = pTail;
    if (pPrev) {
        pPrev->next = pRevTail;
    } else {
        pCurr = pRevTail;
    }

    return (m != 1) ? head :pCurr;
}

ListNode *Solution::reverseBetweenRecursive(ListNode *head, ListNode *pPrev, ListNode **ppTail, int rest) {
    ListNode *pCurr = head;
    
    if (rest) {
        head = pCurr->next;
        pCurr->next = pPrev;
        pPrev = pCurr;
        pCurr = reverseBetweenRecursive(head, pPrev, ppTail, --rest);
    } else {
        if (pCurr) {
            head = pCurr->next;
            pCurr->next = pPrev;
            *ppTail = head;
        }
    }

    return pCurr;
}

ListNode *Solution::reverseBetween(ListNode *head, int m, int n) {
    // 4ms (beats 2.02%)
    ListNode *pCurr = head;
    ListNode *pPrev = NULL;
    ListNode *pRevHead, *pRevTail;
    ListNode *pOriHead = head, *pPrevRevHead;
    int nCurrPos = 1;
    
    do {
        if (m == n) {
            // no need to reverse
            break;
        }
    
        for (; nCurrPos <= n; nCurrPos++) {
            head = pCurr->next;
            
            if (nCurrPos == m) {
                pRevTail = pCurr;
                pPrevRevHead = pPrev;
            } else if (nCurrPos == n) {
                pRevHead = pCurr;
                pRevHead->next = pPrev;
                
                pRevTail->next = head;
                if (pPrevRevHead) {
                    pPrevRevHead->next = pRevHead;
                    pCurr = pOriHead;
                }
                
                break;
            } else if (nCurrPos > m && nCurrPos < n) {
                pCurr->next = pPrev;
            }
            
            pPrev = pCurr;
            pCurr = head;
        }
    } while (false);
    
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