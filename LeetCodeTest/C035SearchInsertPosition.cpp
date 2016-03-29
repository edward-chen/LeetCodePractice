//
//  C035SearchInsertPosition.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/15.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C035SearchInsertPosition.hpp"

using namespace searchingInsertPosition;

int Solution::searchInsert(vector<int> &nums, int target) {
    // 8 ms~ 12 ms (only beats 4.67% ~ 0.46%)
    int inputSize = (int) nums.size();
    int i = 0;
    for (; i < inputSize; i++) {
        int val = nums[i];
        if (val >=  target) {
            return i;
        }
    }
    return i;
}

int Solution::searchInsertBinarySearchVer(vector<int> &nums, int target) {
    // 8 ms~ 12 ms (only beats 4.67% ~ 0.46%)
    int nHitPos = -1;
    int nLeft = 0, nRight = nums.size() - 1;
    
    while(nLeft <= nRight) {
        int mid = (nLeft + nRight) / 2;
        
        int val = nums[mid];
        if (target == val) {
            nHitPos = mid;
            printf("##hit##\n");
            break;
        } else if (target < val) {
            nRight = mid - 1;
            printf("##not hit, nRight: %d\n", nRight);
        } else {
            nLeft = mid + 1;
            printf("##not hit, nLeft: %d\n", nLeft);
        }
    }
    
    if (nHitPos == -1) nHitPos = nLeft;
    
    return nHitPos;
}

int Solution::searchInsertSTL(vector<int> &nums, int target) {
    // 8 ms~ 12 ms (only beats 4.67% ~ 0.46%)
    return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}