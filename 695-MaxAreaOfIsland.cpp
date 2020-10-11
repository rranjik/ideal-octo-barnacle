class Solution {
public:
    vector<vector<bool>> v;
    int m;
    int n;
    vector<vector<int>> g;
    int dfs(int i, int j){
        if(i<0||j<0||i>=m||j>=n||g[i][j]==0||v[i][j]) return 0;
        v[i][j] = true;
        int r = dfs(i+1, j)+dfs(i-1, j)
            +dfs(i, j+1) + dfs(i, j-1) + 1;
        return r;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->g = grid;
        m = grid.size();
        if(!m) return 0;
        n = grid[0].size();
        int res = 0;
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!v[i][j]){
                    res = max(res, dfs(i, j));
                }
            }
        }
        return res;
    }
};
