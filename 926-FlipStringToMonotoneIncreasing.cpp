class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        //prefixSum
        vector<int> p(n+1, 0);
        for(int i = 0; i<n; i++){
            p[i+1] = p[i]+(s[i]=='1'?1:0);
        }
        int res = numeric_limits<int>::max();
        for(int i = 0; i<n+1; i++){
            res = min(res, p[i] + n - i - (p[n]-p[i]));
        }
        return res;
    }
};
