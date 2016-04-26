//
//  C013Roman2Integer.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/26.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C013Roman2Integer.hpp"

using namespace roman2Integer;

// range is from: 1 to 3999 // (I, V, X, L, C, D, M)


// digit number | roman number
// -------------------------------
//          1   |   I
//          2   |   II
//          3   |   III
//          4   |   IV
//          5   |   V
//          6   |   VI
//          7   |   VII
//          8   |   VIII
//          9   |   IX
//         10   |   X
//         40   |   XL
//         50   |   L
//         90   |   XC
//        100   |   C
//        400   |   CD
//        500   |   D
//        900   |   CM
//       1000   |   M
//       5000   |   v

int Solution::romanToInt(string s) {
    // 36 ~ 41 ms
    int nVal = 0;
    int val[256] = {0};
    
    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;
    
    do {
        int len = s.length();
        if (!len) break;
        
        for (int i = 0; i < len; i++) {
            int nCurrVal = val[s[i]];
            nVal += nCurrVal;
            if (i != len - 1) {
                int nNextVal = val[s[i + 1]];
                if (nCurrVal < nNextVal) {
                    nVal += (nNextVal - (nCurrVal << 1));
                    i++;
                }
            }
        }
    } while (false);
    
    
    return nVal;
}