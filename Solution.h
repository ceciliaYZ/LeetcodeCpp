//
//  Solution.h
//  Leetcode
//
//  Created by Cecilia on 6/26/16.
//  Copyright © 2016 Cecilia. All rights reserved.
//
#include <vector>
#ifndef Solution_h
#define Solution_h
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums);
    void gameOfLife(vector<vector<int>>& board);
    bool wordPattern(string pattern, string str);
    vector<int> topKFrequent(vector<int>& nums, int k);
};

#endif /* Solution_h */
