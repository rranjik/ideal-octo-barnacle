class Solution {
public:
    vector<vector<int>> c;
    int lcs(const string& a, const string& b, int i, int j){
        if(i<0||j<0) return 0;
        if(c[i][j]!=-1) return c[i][j];
        int res = 0;
        if(a[i]==b[j]) res = lcs(a, b, i-1, j-1)+1;
        else res = max(lcs(a, b, i, j-1), lcs(a, b, i-1, j));
        return c[i][j] = res;
    }
    bool isValidPalindrome(string s, int k) {
        auto rs = s;
        int n = s.size();
        c = vector<vector<int>>(n, vector<int>(n, -1));
        reverse(rs.begin(), rs.end());
        auto pallen = lcs(s, rs, n-1, n-1);
        return n-pallen<=k;
    }
};
