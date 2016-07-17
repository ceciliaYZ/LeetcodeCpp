//
//  WordPattern.cpp
//  Leetcode
//
//  Created by Cecilia on 7/13/16.
//  Copyright © 2016 Cecilia. All rights reserved.
//
#include "Solution.h"
#include <string>
#include <unordered_map>
#include <sstream>

bool Solution::wordPattern(string pattern, string str){
    size_t sz=pattern.length();
    stringstream ss(str);
    string tok;
    unordered_map<char, string> map;
    unordered_map<string, char> rmap;

    for (size_t i=0; i<sz; i++) {
        if(!getline(ss, tok, ' ')){
            return false;
        }
        if(map.emplace(pattern[i],tok).first->second!=tok){
            return false;
        }
        if(rmap.emplace(tok,pattern[i]).first->second!=pattern[i]){
            return false;
        }
    }
    return ! getline(ss, tok, ' ');
}