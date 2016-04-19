//
//  C007ReverseInteger.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/19.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C007ReverseInteger.hpp"

using namespace Reverse_Integer;

int Solution::reverse(int x) {
    // 8 ms
    int nOut = 0; // 0 also for overflow caused by reverse
    bool bPositive = (x >= 0) ? true : false;
    
    do {
        if (0 == x) {
            break;
        }
        
        unsigned long y = (bPositive) ? x : -(x);
        unsigned long revY = 0;

        while (y) {
            revY *= 10;
            revY += (y % 10);
            y /= 10;
        }
        
        if (revY <= INT32_MAX) {
            nOut = (int) revY;
            if (!bPositive) {
                nOut = 0 - nOut;
            }
        }
    } while (false);
    
    return nOut;
}