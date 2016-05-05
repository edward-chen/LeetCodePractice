//
//  C125ValidPalindrome.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/5/5.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C125ValidPalindrome.hpp"

using namespace ValidPalindrome;

bool Solution::isPalindrome(string s) {
    // 14 ms
    bool bRet = true;
    
    do {
        // 1st remove all symbols
        int i = 0;
        int size = (int) s.size();
        if (size == 0) break;
        if (size == 1) break;
        
        string calStr;
        for (int i = 0; i < size; i++) {
            if (std::isalnum(s[i]))
                calStr += std::tolower(s[i]);
        }
        
        // compare elements of string
        size = (int) calStr.size();
        if (size <= 1) break;
        
        int mid = size / 2;
        int endIdx = size - 1;
        
        i = 0;
        if (size % 2) {
            // odd
            for (; i < mid; i++) {
                if (calStr[i] != calStr[endIdx - i]) {
                    bRet = false;
                    break;
                }
            }
        } else {
            // even
            for (; i < mid; i++) {
                if (calStr[mid + i] != calStr[mid - (i + 1)]) {
                    bRet = false;
                    break;
                }
            }
        }
    } while (false);

    return bRet;
}
