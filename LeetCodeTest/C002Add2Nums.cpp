//
//  C002Add2Nums.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/10.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C002Add2Nums.hpp"
using namespace add2nums;

ListNode* Solution::addTwoNumbers_ver1(ListNode* l1, ListNode* l2) {
    // this can only gain 36 ~ 40 ~ 44ms (beat 63% ~ 18% ~ 7%)
    int carry = 0;
    
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    ListNode *pHead = new ListNode(0);
    ListNode *pCurr = NULL;
    
    do {
        int value = (((l1) ? l1->val: 0) +
                     ((l2) ? l2->val: 0) + carry);
        (carry = value >= 10 ? 1: 0) ? value -= 10: 0;
        
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        
        if (!pCurr) {
            pCurr = pHead;
            pCurr->val = value;
        } else {
            pCurr->next = new ListNode(value);
            pCurr = pCurr->next;
        }
    } while((l1 || l2 || carry));
    
    //if (carry) {
    //  pCurr->next = new ListNode(carry);
    //}
    
    return pHead;
}

ListNode* Solution::addTwoNumbers_ver2(ListNode* l1, ListNode* l2) {
    // this can only gain 36 ~ 40ms (beat 63% ~ 18%)
    
    int carry = 0;
    
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    ListNode *pHead = l1;
    ListNode *pCurr = pHead;
    
    do {
        int value = (((l1) ? l1->val: 0) +
                     ((l2) ? l2->val: 0) + carry);
        (carry = value >= 10 ? 1: 0) ? value -= 10: 0;
        
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        
        pCurr->val = value;
        if (!pCurr->next && l2) {
            pCurr->next = new ListNode(0);
            pCurr = pCurr->next;
        } else {
            if (pCurr->next) pCurr = pCurr->next;
        }
    } while(l1 || l2);
    
    if (carry) {
        pCurr->next = new ListNode(carry);
    }
    
    return pHead;
}

Solution::Solution(int ver) {
    switch (ver) {
        case VER_MIN:
        case VER_MAX:
            m_nVer = ver;
            break;
            
        default:
            m_nVer = VER_MIN;
            printf("invalid version, use default ver: %d\n", VER_MIN);
            break;
    }
}

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode* l2) {
    switch (m_nVer) {
        case VER_MAX:
            return addTwoNumbers_ver2(l1, l2);
        default:
            return addTwoNumbers_ver1(l1, l2);
    };
}


void CTestGen::freeList(ListNode *pListNode) {
    ListNode *pListCurr = pListNode;
    ListNode *pListNext = NULL;
    while(pListCurr){
        pListNext = pListCurr->next;
        delete pListCurr;
        pListCurr = pListNext;
    }
}

void CTestGen::dumpList(const ListNode *pListNode) {
    const ListNode *pTmp = pListNode;
    printf("{");
    while (true) {
        if (pTmp->next != NULL) {
            printf("%d, ", pTmp->val);
        } else {
            printf("%d", pTmp->val);
            break;
        }
        pTmp = pTmp->next;
    }
    printf("}\n");
    
}

ListNode * CTestGen::initList(const int *pArray, int arraySize) {
    ListNode *pListHead = NULL;;
    ListNode *pListCurr = NULL;
    
    for(int i = 0; i < arraySize; i++) {
        ListNode *pNode = new ListNode(pArray[i]);
        if (pListHead == NULL) {
            pListHead = pListCurr = pNode;
        } else {
            pListCurr->next = pNode;
            pListCurr = pNode;
        }
        
    }
    
    return pListHead;
}
