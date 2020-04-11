class Solution {
public:
    string s1;
    string s2;
    int sum(string s, int i){
        int res = 0;
        for(int j = 0; j<=i; j++){
            res += s[j];
        }
        return res;
    }
    vector<vector<int>> c;
    int dp(int i, int j){
        if(i<0){
            return sum(s2, j);
        } 
        if(j<0){
            return sum(s1, i);
        }
        if(c[i][j]!=-1) return c[i][j];
        if(s1[i] == s2[j]){
            c[i][j] = dp(i-1, j-1);
            return c[i][j];
        } else {
            c[i][j] = min(dp(i-1, j)+s1[i], dp(i, j-1)+s2[j]);
            return c[i][j];
        }
    }
    int minimumDeleteSum(string _s1, string _s2) {
        s1 = _s1;
        s2 = _s2;
        c = vector<vector<int>>(s1.length(), vector<int>(s2.length(), -1));
        return dp(s1.length()-1, s2.length()-1);
    }
};
