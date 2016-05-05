//
//  C014LongestCommonPrefix.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/5/5.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C014LongestCommonPrefix.hpp"

using namespace LongestCommonPrefix;


string Solution::longestCommonPrefix(vector<string> &strs) {
    string output;
    do {
        int nSize = strs.size();
        
        if (!nSize) break;
        
        if (nSize == 1) {
            output = strs[0];
            break;
        }
        
        int n1stStrSize = strs[0].size();
        bool bContains = true;
        string firstStr = strs[0];
        if (!firstStr.size()) {
            break;
        }
        
        output += firstStr[0];
        for (int i = 1; i <= n1stStrSize; i++) {
            for (int j = 1; j < nSize; j++) {
                if (strs[j].find(output) != 0) {
                    bContains = false;
                    break;
                }
            }
            
            if (bContains) {
                if (i == n1stStrSize) break;
                output += firstStr[i];
            } else {
                output.pop_back();
                break;
            }
        }
    } while (false);
    
    return output;
}