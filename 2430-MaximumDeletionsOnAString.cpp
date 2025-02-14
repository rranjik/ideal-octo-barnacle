class Solution {
public:

    int deleteString(string a) {
        auto s = a;
        int n = s.size();
        auto c = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        vector<int> dp(n, 1);
        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(s[i]==s[j])
                    c[i][j] = c[i+1][j+1]+1;
                if(c[i][j]>=j-i){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return dp[0];
    }
};
