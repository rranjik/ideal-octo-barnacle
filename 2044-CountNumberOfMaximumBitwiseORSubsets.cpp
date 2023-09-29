class Solution {
public:
    int countMaxOrSubsets(vector<int>& a) {
        int goal = 0;
        int n = a.size();
        int res = 0;
        vector<int> dp(1<<n);
        for(const auto& v : a) goal|=v;
        for(int m = 1; m<1<<n; m++){
            int lbit = m&(~(m-1));
            dp[m] = dp[m-lbit]|a[__builtin_ctz(lbit)];
            if(dp[m]==goal) ++res;
        }
        return res;
    }
};
