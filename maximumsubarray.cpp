class Solution {
 public :
    vector<int> n;
    unordered_map<int, int> m;
    int dp(int i){
        if(m.find(i)!=m.end()){
            return m[i];
        }
        if(i==0){
            m.insert({i,n[0]});
            return m[i];
        }else{
            m.insert({i, max(dp(i-1)+n[i], n[i])});
            return m[i];
        }
    }
    int maxSubArray (vector < int > & nums) {
        n = nums;
        int mx = numeric_limits<int>::min();
        dp(nums.size()-1);
        for(auto it : m){
            mx = max(mx, it.second);
        }
        return mx;
    }
};
