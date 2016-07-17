//
//  moveZeroes.cpp
//  Leetcode
//
//  Created by Cecilia on 6/26/16.
//  Copyright © 2016 Cecilia. All rights reserved.
//

#include "Solution.h"

void Solution:: moveZeroes(vector<int>& nums) {
    int fir=0, sec=1;
    while (sec<nums.size()) {
        if(nums[fir]==0){
            if(nums[sec]==0){
                sec++;
            }else{
                swap(nums[fir++],nums[sec++]);
            }
        }else{
            fir++;
            if(sec==fir){
                sec++;
            }
        }
    }
}
