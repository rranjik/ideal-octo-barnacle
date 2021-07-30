class Twitter {
public:
    struct tweet{
        int timestamp;
        int tweetid;
        int userid;
        tweet(int _ts, int _t, int _u):timestamp(_ts), tweetid(_t), userid(_u){}
        bool operator<(const tweet& t) const {return timestamp>t.timestamp;}
    };
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> followmap;
    set<tweet> tweets;
    Twitter() {
        
    }
    
    int time{};
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        followmap[userId].insert(userId);
        tweets.insert(tweet(time, tweetId, userId));
        time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int num = 0;
        auto it = tweets.begin();
        while(num<10&&it!=tweets.end()){
            if(followmap[userId].find(it->userid)!=followmap[userId].end()){
                res.push_back(it->tweetid);
                num++;
            }
            it++;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            followmap[followerId].erase(followeeId);
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
