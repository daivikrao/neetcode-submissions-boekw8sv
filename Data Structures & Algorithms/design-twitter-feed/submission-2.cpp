class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,set<int>> followers;
    long long count;
    Twitter() { 
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        vector<int> res;

        for(auto i:tweets[userId]){
            pq.push(i);
        }

        for(int follower: followers[userId]){
            for(auto it: tweets[follower]){
                pq.push(it);
            }
        }

        while(!pq.empty() && res.size() < 10){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
