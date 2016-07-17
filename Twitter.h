//
//  Twitter.h
//  Leetcode
//
//  Created by Cecilia on 7/13/16.
//  Copyright © 2016 Cecilia. All rights reserved.
//

#ifndef Twitter_h
#define Twitter_h
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
using namespace std;
class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> user_follow_info;
    vector<pair<int,int>> posted_tweet;
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        posted_tweet.push_back(std::make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto end=user_follow_info[userId].end();
        unordered_set<int> follow=user_follow_info[userId];
        for (int i=posted_tweet.size()-1; i>=0; i--) {
            pair<int,int> tw=posted_tweet[i];
            int postuser=tw.first;
            if(postuser==userId || follow.find(postuser)!=end){
                res.push_back(tw.second);
                if (res.size()==10) {
                    break;
                }
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            user_follow_info[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        user_follow_info[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

#endif /* Twitter_h */
