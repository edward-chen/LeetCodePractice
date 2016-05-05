//
//  C009PalindromeNumber.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/5/5.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C009PalindromeNumber.hpp"

using namespace PalindromeNumber;

bool Solution::isPalindrome(int x) {
    // 84 ms
    bool bRet = true;
    
    do {
        if (x < 0 ) {
            bRet = false;
            break;
        }
        
        string xStr = std::to_string(x);
        int len = xStr.size();
        
        if (len == 1) {
            break;
        }
        
        int mid = len / 2;
        int i = 0;
        int endIdx = len - 1;
        if (len % 2) {
            // odd
            for (; i < mid; i++) {
                if (xStr[i] != xStr[endIdx - i]) {
                    bRet = false;
                    break;
                }
            }
        } else {
            // even
            for (; i < mid; i++) {
                if (xStr[mid + i] != xStr[mid - (i +1)]) {
                    bRet = false;
                    break;
                }
            }
        }
    } while (false);
    
    return bRet;
}