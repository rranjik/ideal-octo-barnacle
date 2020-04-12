class Solution {
public:
    string s1;
    string s2;
    vector<vector<int>> c;
    int dp(int i, int j){
        if(i<0){
            return 0;
        }
        if(j<0){
            return 0;
        }
        if(c[i][j]!=-1) return c[i][j];
        if(s1[i]==s2[j]){
            c[i][j] =  dp(i-1, j-1)+1;
            return c[i][j];
        }
        c[i][j] = max(dp(i-1, j), dp(i, j-1));
        return c[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        c = vector<vector<int>>(s1.length(), vector<int>(s2.length(), -1));
        return dp(s1.length()-1, s2.length()-1);
    }
};
