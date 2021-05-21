class Solution {
public:
    bool isMatch(string s, string p) {
        s = "0"+s;
        p = "0"+p;
        vector<vector<bool>> dp(s.length(), vector<bool>(p.length()));
        dp[0][0] = true;
        for(int i = 1; i<dp[0].size(); i++){
            if(p[i]=='*') dp[0][i] = dp[0][i-1];
        }
        
        for(int i = 1; i<dp.size(); i++){
            for(int j = 1; j<dp[i].size(); j++){
                if(p[j]=='?'||p[j]==s[i]) 
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j]=='*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
        
        return dp[s.length()-1][p.length()-1];
    }
};
