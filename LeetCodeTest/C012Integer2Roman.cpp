//
//  C012Integer2Roman.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/27.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C012Integer2Roman.hpp"

using namespace Int2Roman;

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
//      10000   |   x

#define M_VAL_STR(a, b, c) \
{"", #a, #a#a, #a#a#a, #a#b, #b, #b#a, #b#a#a, #b#a#a#a, #a#c}

char * Solution::convertThusand(int num) {
    char * val [10] = M_VAL_STR(M, v, x);
    return val [num];
}

char * Solution::convertHundred(int num) {
    char * val [10] = M_VAL_STR(C, D, M);
    return val[num];
}

char * Solution::convertDecimal(int num) {
    char * val [10] = M_VAL_STR(X, L, C);
    return val[num];
}

char * Solution::convertDigit(int num) {
    char * val [10] = M_VAL_STR(I, V, X);
    return val[num];
}


string Solution::intToRoman(int num){
    // 24  ~ 28ms
    string output;
    
    do {
        if (!num) break;

        output += convertThusand(num / 1000);
        output += convertHundred((num %= 1000) / 100);
        output += convertDecimal((num %= 100) / 10);
        output += convertDigit((num %= 10));
        

    } while (false);
    
    
    return output;
}