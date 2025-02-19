class Solution {
public:
    void print(const vector<int>& v) {
        for(const auto& x : v) 
            cout<<x<<" ";
        cout<<endl;
    }
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> qs(n+1);
        for(const auto& q : requests){
            qs[q[0]]+=1;
            qs[q[1]+1]-=1;
        }
        for(int i = 1; i<n; i++){
            qs[i]+=qs[i-1];
        }
        print(qs);
        priority_queue<int> q;
        for(int i = 0; i<n; i++){
            q.push(qs[i]);
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        long long res = 0;
        long long mod = 1e9+7;
        for(const auto& n : nums){
            long long t = q.top();
            q.pop();
            res+=(t*n);
            res%=mod;
        }
        return res;
    }
};
