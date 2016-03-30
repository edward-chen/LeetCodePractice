//
//  C092ReverseLinkedListII.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/30.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C092ReverseLinkedListII_hpp
#define C092ReverseLinkedListII_hpp

#include <stdio.h>
#include "BasicDataStructure.h"

namespace ReverseLinkedListII {
    class Solution {
    private:
        unsigned int m_nSize;
        ListNode *m_pHead;
        
        void dumpList() {
            dumpList(m_pHead, "(linked list)");
        }
        
    public:
        Solution(unsigned int size = 10);
        ~Solution();
        
        
        ListNode *getHead() { return m_pHead; }
        void setHead(ListNode *pNode) { m_pHead = pNode; }
        
        void dumpList(ListNode *pNode, const char *pszMsg);
    
        ListNode *reverseBetweenFunc(ListNode *head, int m, int n, unsigned char opt);
        
        ListNode *reverseBetweenRecursive(ListNode *head, int m, int n);
        ListNode *reverseBetweenRecursive(ListNode *head, ListNode *pPrev, ListNode **ppTail, int rest);
        ListNode *reverseBetween(ListNode *head, int m, int n);
    };
}


#endif /* C092ReverseLinkedListII_hpp */
