//
//  C008StringToInteger.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/20.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C008StringToInteger.hpp"

using namespace String2Int;

int Solution::myAtoi(string str) {
    // 8 ~ 12 ms
    int output = 0;
    int overFlowVal = INT32_MAX / 10;
    int size = (int)str.length();
    
    do {
        if (!size) break;;
        
        bool bMinus = false;
        bool bPositive = false;
        bool bHasDigit = false;
        bool bHasSpace = false;
        bool bOverFlow = false;
        for (std::string::iterator it = str.begin(); it < str.end(); it++) {
            char val = *it;
            
            if (isspace(val)) {
                if (bHasDigit || bPositive || bMinus) break;
                bHasSpace = true;
            } else if (isdigit(val)) {
                if (output > overFlowVal) {
                    overFlowVal = true;
                    if (bMinus) {
                        output = INT32_MIN;
                    } else {
                        output = INT32_MAX;
                    }
                    break;
                } else if (output == overFlowVal) {
                    int lastDigit = val - '0';
                    int nOffset = 7;
                    output *= 10;
                    
                    if (bMinus) {
                        nOffset = 8;
                    }
                    
                    lastDigit = ((lastDigit - nOffset) >= 0) ? nOffset: lastDigit;
                    
                    output += lastDigit;
                    break;
                }
                
                output *= 10; // <<< how to avoid over flow
                output += (val - 48);
                bHasDigit = true;
            } else if (val == '-') {
                if (bHasDigit || bPositive || bMinus) break;
                bMinus = true;
            } else if (val == '+') {
                if (bHasDigit || bPositive || bMinus) break;
                bPositive = true;
            } else {
                break;
            }
        }
        
        if (!bOverFlow) {
            if (bMinus) output = -output;
        }
    } while (false);
    
    return output;
}
