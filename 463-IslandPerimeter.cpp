class Solution {
public:
    void dfs(int i, int j, int& res){
        if(i<0||j<0||i>=m||j>=n||!g[i][j]||v[i][j]) return;
        v[i][j] = true;
        if(!g[i][j]) return;
        if(i-1>=0) {
            if(g[i-1][j]){
                dfs(i-1, j, res);
            }else{
                res++;
            }
        }else res++;
        if(j-1>=0) {
            if(g[i][j-1]){
                dfs(i, j-1, res);
            }else{
                res++;
            }
        }else res++;
        if(i+1<m) {
            if(g[i+1][j]){
                dfs(i+1, j, res);
            }else{
                res++;
            }
        }else res++;
        if(j+1<n) {
            if(g[i][j+1]){
                dfs(i, j+1, res);
            }else{
                res++;
            }
        }else res++;
    }
    vector<vector<bool>> v;
    vector<vector<int>> g;
    int m;
    int n;
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        if(!m) return 0;
        n = grid[0].size();
        g = grid;
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]) {
                    dfs(i, j, res);
                    return res;
                }
            }
        }
        return res;
    }
};
