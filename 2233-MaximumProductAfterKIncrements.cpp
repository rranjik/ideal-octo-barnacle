class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(const auto& n : nums){
            pq.push(n);
        }
        while(k){
            auto t = pq.top();
            pq.pop();
            t++;
            k--;
            pq.push(t);
        }
        long long res = 1;
        int m = 1e9+7;
        while(!pq.empty()){
            res*=pq.top();
            res%=m;
            pq.pop();
        }
        return res;
    }
};
