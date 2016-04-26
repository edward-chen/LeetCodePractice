//
//  C012Integer2Roman.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/27.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C012Integer2Roman_hpp
#define C012Integer2Roman_hpp

#include <stdio.h>
#include <string>
#include "BasicDataStructure.h"

using namespace std;

namespace Int2Roman {

#define M_VAL_STR(a, b, c) \
{"", #a, #a#a, #a#a#a, #a#b, #b, #b#a, #b#a#a, #b#a#a#a, #a#c}
    
    class Solution {
    private:
        char * convertThusand(int num);
        char * convertHundred(int num);
        char * convertDecimal(int num);
        char * convertDigit(int num);
    public:
        string intToRoman(int num);
    };
}

#endif /* C012Integer2Roman_hpp */
