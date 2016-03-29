//
//  C001TwoSum.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/10.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C001TwoSum.hpp"

using namespace two_sum;
vector <int> Solution::twoSum(vector<int> &nums, int target) {
    // 8ms ~ 12ms (beats 98.34% ~ 85.58%)
    
    const int ASIZE = 60001;
    arrayTag array [ASIZE];
    int mid = ASIZE / 2;
    
    vector <int> output;
    for (int i = 0; i < nums.size(); i++) {
        int value = nums[i];
        int idx = mid + value;
        if (array [idx].idx == -1) {
            array [idx].idx = i;
        } else {
            if (!array [idx].notThis) {
                if (target == 0 || (target - value) == value) {
                    output.push_back(array[idx].idx);
                    output.push_back(i);
                    return output;
                } else {
                    array[idx].notThis = true; // <<< this code might have some problem
                }
            }
        }
    }
    
    for (int j = 0; j < nums.size(); j++) {
        int value = nums[j];
        int idx = value + mid;
        if (!array[idx].notThis) {
            int delta = target - value + mid;
            if (array[delta].idx != -1 && idx != delta) {
                output.push_back(array[idx].idx);
                output.push_back(array[delta].idx);
                break;
            }
        }
    }
    
    return output;
}