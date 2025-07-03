#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Twitter {
    private:
        int timestamp;

        unordered_map<int, unordered_set<int>> followMap;

        unordered_map<int, vector<pair<int, int>>> tweetMap;
public:
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        for(auto& tweet: tweetMap[userId]){
            pq.push(tweet);
        }

        for(int followeeId : followMap[userId]){
            for(auto& tweet: tweetMap[followeeId]){
                pq.push(tweet);
            }
        }

        vector<int> result;
        int cnt =0;
        while(!pq.empty() && cnt < 10){
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
