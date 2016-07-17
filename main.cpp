//
//  main.cpp
//  Leetcode
//
//  Created by Cecilia on 5/21/16.
//  Copyright © 2016 Cecilia. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Solution.h"
#include "Twitter.h"
using namespace std;

void printArray(vector<int>& nums){
    for (int i=0; i<nums.size(); i++) {
        cout<<nums[i]<<", ";
    }
    cout<<"\n";
}
void printArrays(vector<vector<int>>& nums){
    for (int i=0; i<nums.size(); i++) {
        for (int j=0; j<nums[0].size(); j++) {
            cout<<nums[i][j]<<", ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main(int argc, const char * argv[]) {
    Solution s;
    
//    vector<int> nums={1,0,1, 0, 3, 12,0};//{1,0, 1, 0, 3, 12,0};
//    printArray(nums);
    //s.moveZeroes(nums);
    
    vector<vector<int>> numsV={{0,1}};
//                                {{1,1,0,0,0,0},
//                                {1,1,0,0,0,0},
//                                {0,0,1,1,0,0},
//                                {0,0,1,1,0,0},
//                                {0,0,0,0,0,0},
//                                {0,0,0,0,0,0}};
    s.gameOfLife(numsV);
    printArrays(numsV);
    
    std::cout << std::boolalpha << s.wordPattern("abba", "dog cat cat dog") <<std::endl;
    std::cout << std::boolalpha << s.wordPattern("abba", "dog cat cat fish") <<std::endl;
    std::cout << std::boolalpha << s.wordPattern("aaaa", "dog cat cat dog") <<std::endl;
    std::cout << std::boolalpha << s.wordPattern("abba", "dog dog dog dog") <<std::endl;
    std::cout << std::boolalpha << s.wordPattern("", "") <<std::endl;
    std::cout << std::boolalpha << s.wordPattern("abba", "dog dog dog") <<std::endl;
    std::cout << std::boolalpha << s.wordPattern("abb", "dog dog dog dog") <<std::endl;
    std::cout << std::boolalpha << s.wordPattern("aaa", "aa aa aa aa") <<std::endl;
    
    Twitter twitter = *new Twitter();
    
    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);
    
    // User 1's news feed should return a list with 1 tweet id -> [5].
    auto v=twitter.getNewsFeed(1);
    printArray(v);
    // User 1 follows user 2.
    twitter.follow(1, 2);
    
    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);
    
    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    v=twitter.getNewsFeed(1);
    printArray(v);
    
    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);
    
    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    v=twitter.getNewsFeed(1);
    printArray(v);
    vector<int> v1={1,1,1,1,2,2,3};
    s.topKFrequent(v1, 2);
    
    
    
    
    cout<<"\nDone\n";
    return 0;
}
















