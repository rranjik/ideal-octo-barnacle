class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        res[0][0] = grid[0][0];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int u = numeric_limits<int>::max();
                int l = numeric_limits<int>::max();
                if(i-1>=0) u = res[i-1][j];
                if(j-1>=0) l = res[i][j-1];
                u = (u==l&&(u==numeric_limits<int>::max()))?0:u;
                res[i][j] = min(u, l) + grid[i][j];
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        return res[n-1][m-1];
    }
};
