class Solution {
public:
    string lcs(string a, string b){
        int m = a.size();
        int n = b.size();
        vector<vector<string>> dp(m+1, vector<string>(n+1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(a[i]==b[j]){
                    dp[i+1][j+1] = dp[i][j]+a[i];
                }else{
                    dp[i+1][j+1] = (dp[i][j+1].size()>dp[i+1][j].size()) ? dp[i][j+1]: dp[i+1][j];
                }
            }
        }
        return dp[m][n];
    }
    string shortestCommonSupersequence(string a, string b) {
        int i = 0; int j = 0;
        string l = lcs(a, b);
        cout<<"l = "<<l<<endl;
        string res;
        for(const auto& c : l){
            while(a[i]!=c) {
                res+=a[i];
                i++;
            }
            i++;
            while(b[j]!=c) {
                res+=b[j];
                j++;
            }
            j++;
            res+=c;
        }
        return res+a.substr(i)+b.substr(j);
    }
};
