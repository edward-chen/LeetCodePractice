//
//  C001TwoSum.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/10.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C001TwoSum_hpp
#define C001TwoSum_hpp

#include <stdio.h>
#include <vector>

using namespace std;

typedef struct arrayTag {
    int idx = -1;
    bool notThis = false;
} myArr;


namespace two_sum {
    class Solution {
    public:
        vector <int> twoSum(vector <int> &nums, int target);
    };
}


#endif /* C001TwoSum_hpp */
