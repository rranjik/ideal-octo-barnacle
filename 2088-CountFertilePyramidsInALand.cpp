class Solution {
public:
    int count(vector<vector<int>> g){
        int m = g.size();
        int n = g[0].size();
        int res = 0;
        for(int i = m-2; i>=0; i--){
            for(int j = 1; j<n-1; j++){
                if(g[i][j]&&g[i+1][j]){
                    g[i][j] = min(g[i+1][j-1], g[i+1][j+1])+1;
                    res += g[i][j]-1;
                }      
            }
        }
        return res;
    }
    int countPyramids(vector<vector<int>>& grid) {
        int res = 0;
        res += count(grid);
        reverse(grid.begin(), grid.end());
        res += count(grid);
        return res;
    }
};
