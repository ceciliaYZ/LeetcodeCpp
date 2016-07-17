//
//  TopKFrequent.cpp
//  Leetcode
//
//  Created by Cecilia on 7/14/16.
//  Copyright © 2016 Cecilia. All rights reserved.
//
#include "Solution.h"
#include <unordered_map>

vector<int> Solution::topKFrequent(vector<int>& nums, int k){
    vector<int> res;
    unordered_map<int,int> map;
    for (int num:nums) {
        map[num]++;
    }
    for(auto p : map){
        p=pair<int, int>(p.first,p.second);
        //std::__1::swap(p.first, p.second);
        
    }
//    for (size_t i=0; i<map.size(); i++) {
//        <#statements#>
//    }
    return res;
}

