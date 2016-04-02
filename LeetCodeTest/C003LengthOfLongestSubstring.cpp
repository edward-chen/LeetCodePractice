//
//  C003LengthOfLongestSubstring.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/2.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C003LengthOfLongestSubstring.hpp"

using namespace LengthOfLongestSubstring;


/* Given a string, find the length of the longest substring without
   repeating characters. For example, the longest substring without 
   repeating letters for "abcabcbb" is "abc", which the length is 3. 
   For "bbbbb" the longest substring is "b", with the length of 1.
*/

int Solution::lengthOfLongestSubstringFunc(string s, unsigned short opt) {
    int len = 0;
    switch (opt) {
        case E_ITERATIVE:
            len = lengthOfLongestSubstring(s);
            break;
        case E_DP:
            len = lengthOfLongestSubstringDp(s);
            break;
        default:
            printf("!!unknown option: %d for %s", opt, __func__);
            break;
    }

    return len;
}

int Solution::lengthOfLongestSubstringDp(string s) {
    int nLen = 0;
    
    do {
        // TODO: need to implement code here
    } while (false);
    
    
    return nLen;
}

int Solution::lengthOfLongestSubstring(string s) {
    // 40 ms (beats 40%)
    int nLen = 0, nCurrLen = 0;
    int nStrlen = s.length();
    const int MAP_SIZE  = 256;
    const int half_size = nStrlen / 2;
    int strMapping[MAP_SIZE] = {0};
    
    do {
        if (nLen == nStrlen || 1 == nStrlen) {
            nLen = nStrlen;
            break;
        }
        
        int i = 0, j;
        for (int i = 0; i < nStrlen; i ++) {
            //string subString;
            for (j = i; j < nStrlen; j++) {
                unsigned int val = s[j];
                if (strMapping[val] == 0) {
                    strMapping[val] = 1;
                    nCurrLen++;
                } else {
                    // repeat;
                    break;
                }
            }
            
            if (i == half_size && nCurrLen >= half_size) {
                nLen = (nCurrLen > nLen) ? nCurrLen: nLen;
                break;
            } else {
                if (nCurrLen > nLen) {
                    nLen = nCurrLen;
                }
            }
            
            
            memset (strMapping, 0, MAP_SIZE * sizeof(int));
            nCurrLen = 0;
        }
    
    } while (false);
    
    
    return nLen;
}
