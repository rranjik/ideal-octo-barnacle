class Solution {
public:
    vector<vector<int>> c;
    int dp(int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(c[i][j]!=-1) return c[i][j];
        if(s[i]==s[j]) {
            auto res = dp(i+1, j-1)+2;
            c[i][j] = res; 
        }
        else {
            auto res = max(dp(i+1, j), dp(i, j-1));
            c[i][j] = res; 
        }
        return c[i][j];
    }
    string s;
    int longestPalindromeSubseq(string s) {
        c = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
        this->s = s;
        return dp(0, s.length()-1);
    }
};
