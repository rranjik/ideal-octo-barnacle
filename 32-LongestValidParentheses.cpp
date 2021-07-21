class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int res = 0;
        cout<<"len = "<<s.length()<<endl;
        for(int i = 0; i<s.length(); i++){
            cout<<"i = "<<i<<"; s[i] = "<<s[i]<<endl;
            if(s[i]==')'){
                if(i-1>=0){
                    if(s[i-1]=='('){
                        if((i-dp[i-1]-2)>=0)
                            dp[i] = dp[i-1]+2+dp[i-dp[i-1]-2];
                        else dp[i] = dp[i-1]+2;
                        res = max(res, dp[i]);
                    }else{
                        if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                            if((i-dp[i-1]-2)>=0)
                                dp[i] = dp[i-1]+2+dp[i-dp[i-1]-2];
                            else 
                                dp[i] = dp[i-1]+2;
                            res = max(res, dp[i]);
                        }
                    }
                }
            }
        }
        return res;
    }
};
