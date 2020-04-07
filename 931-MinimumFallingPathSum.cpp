class Solution {
public:
    vector<vector<int>> sq;
    int n;
    vector<vector<int>> c;
    int dp(int i, int l){
        if(l!=-1&&i!=-1&&c[l][i]!=numeric_limits<int>::max()){
            return c[l][i];
        }
        if(l==n-1){
            c[l][i] = sq[l][i];
            return sq[l][i];
        }else {
            int res = numeric_limits<int>::max();
            if(l==-1){
                for(int j = 0; j<n; j++){
                    res = min(res, dp(j, 0));
                }
                return res;
            }else {
                if(i-1>=0){
                    res = min(res, dp(i-1, l+1)+sq[l][i]); 
                }
                res = min(res, dp(i, l+1)+sq[l][i]); 
                if(i+1<n){
                    res = min(res, dp(i+1, l+1)+sq[l][i]); 
                }
                c[l][i] = res;
                return res;
            }
        }
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        sq = A;
        n = A.size();
        c = vector<vector<int>>(n, vector<int>(n, numeric_limits<int>::max()));
        return dp(-1, -1);
    }
};
