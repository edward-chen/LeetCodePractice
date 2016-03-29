//
//  C035SearchInsertPosition.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/15.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef C035SearchInsertPosition_hpp
#define C035SearchInsertPosition_hpp

#include <stdio.h>
#include <vector>

using namespace std;

namespace searchingInsertPosition {
    class Solution {
    public:
        int searchInsert(vector <int> &nums, int target);
        int searchInsertBinarySearchVer(vector <int> &nums, int target);
        int searchInsertSTL(vector <int> &nums, int target);
    };
}

#endif /* C035SearchInsertPosition_hpp */
