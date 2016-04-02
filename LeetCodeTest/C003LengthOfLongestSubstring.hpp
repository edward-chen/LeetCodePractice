//
//  C003LengthOfLongestSubstring.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/2.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C003LengthOfLongestSubstring_hpp
#define C003LengthOfLongestSubstring_hpp

#include <stdio.h>
#include <string>
#include "BasicDataStructure.h"

using namespace std;

namespace LengthOfLongestSubstring {
    class Solution {
    public:
        int lengthOfLongestSubstringFunc(string s, unsigned short opt);
        int lengthOfLongestSubstring(string s);
        int lengthOfLongestSubstringDp(string s);
    };

}
#endif /* C003LengthOfLongestSubstring_hpp */
