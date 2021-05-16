class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1));
        dp[0][0] = true;
        s = "0"+s;
        p = "0"+p;
        for(int i = 2; i<dp[0].size(); i++){
            if(p[i]=='*') 
                dp[0][i] = dp[0][i-2];
        }
        for(int i = 1; i<dp.size(); i++){
            for(int j = 1; j<dp[i].size(); j++){
                if(p[j]=='.'||p[j]==s[i]) 
                    dp[i][j] = dp[i-1][j-1];
                else {
                    if(p[j]=='*'){
                        dp[i][j] = dp[i][j]||dp[i][j-2];
                        if(p[j-1]==s[i]||p[j-1]=='.') dp[i][j]=dp[i][j]||dp[i-1][j];
                    }
                }
            }
        }
        return  dp[s.length()-1][p.length()-1];
    }
};
