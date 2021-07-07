class Solution {
public:
    void clean(int i){
        if(!q.empty()&&q.front()==i-k) q.pop_front();
        while(!q.empty()&&n[q.back()]<n[i]) q.pop_back();
    }
    deque<int> q;
    vector<int> n;
    int k;
    vector<int> maxSlidingWindow(vector<int>& nums, int K) {
        n = nums;
        this->k = K;
        int len = nums.size();
        if(!len||!k) return n;
        
        for(int i = 0; i<k ;i++){
            clean(i);
            q.push_back(i);
        }
        
        vector<int> res;
        res.push_back(n[q.front()]);
        for(int i = k; i<n.size(); i++){
            clean(i);
            q.push_back(i);
            res.push_back(n[q.front()]);
        }
        return res;
    }
};
