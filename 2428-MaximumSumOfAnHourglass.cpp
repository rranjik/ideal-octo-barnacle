class Solution {
public:
    int maxSum(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        int res = 0;
        for(int i = 0; i<m-2; i++){
            for(int j = 0; j<n-2; j++){
                int hg = 0;
                hg = g[i][j]+g[i][j+1]+g[i][j+2]+
                            g[i+1][j+1]+
                    g[i+2][j]+g[i+2][j+1]+g[i+2][j+2];
                res = max(res, hg);
            }
        }
        return res;
    }
};
