//
//  C006ZigzagConversion.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/19.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C006ZigzagConversion.hpp"


using namespace Zigzag_conversion;

string Solution::convert(string s, int numRows) {
    // 24 ms (beats 34.41%)
    string output = "";
    int restStrLen = (int) s.size();
    
    do {
        if (numRows <= 1 || numRows >= restStrLen) {
            output = s;
            break;
        }
 
        int n1stColElementNum = numRows;
        int n2ndColElementNum = !(numRows - 2) ? numRows: (numRows - 2);
        string *pStrArray = new string [numRows];
        
        int offset = (numRows == 2)? 2: 1;
        int currCol = 0;
        int currIdx = 0;
        
        while (restStrLen) {
            if (!(currCol % 2)) {
                // even col
                for (int i = 0; i < n1stColElementNum && restStrLen; i++) {
                    pStrArray[i] += s[currIdx++];
                    restStrLen--;
                }
            } else {
                // odd col
                for (int j = 0; j < n2ndColElementNum && restStrLen; j++){
                    pStrArray[(numRows - 1) - j - 1] += s[currIdx++];
                    restStrLen--;
                }
            }
            
            // if rows num == 2, even col acts like odd col
            currCol += offset;
        }
        
        for(int i = 0; i < numRows; i++) {
            output += pStrArray[i];
        }
        delete [] pStrArray;
        
    } while (false);
    
    return output;
}