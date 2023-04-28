class Solution {
public:
    int dp(const vector<int>& a, int i, int j){
        if(c[i][j]!=-1) return c[i][j];
        int res = numeric_limits<int>::max();
        if(i+1==j) {
            c[i][j] = 0;
            return 0;
        }
        for(int k = i+1; k<j; k++){
            res = min(res, dp(a, i, k)+a[i]*a[k]*a[j]+dp(a, k, j));
        }
        c[i][j] = res;
        return res;
    }
    vector<vector<int>> c;
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        c = vector<vector<int>>(n, vector<int>(n, -1));
        return dp(A, 0, n-1);
    }
};
