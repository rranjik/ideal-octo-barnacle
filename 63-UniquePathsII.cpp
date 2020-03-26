class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n = og.size();
        if(!n) return 0;
        int m = og[0].size();
        vector<vector<long long int>> res(n, vector<long long int>(m, 0));
        res[0][0] = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!og[i][j]){
                    if(i-1>=0) res[i][j]+=res[i-1][j];
                    if(j-1>=0) res[i][j]+=res[i][j-1];
                } else res[i][j] = 0;
            }
        }
        return res[n-1][m-1];
    }
};
