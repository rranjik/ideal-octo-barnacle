class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> g;
    int getMaximumGold(vector<vector<int>>& grid) {
        g = grid;
        int res  = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j]!=0){
                    auto r = dfs(i, j);
                    //cout<<"res["<<i<<"]["<<j<<"]"<<" = "<<res[i][j]<<endl;
                    res = max(r, res);
                }
            }
        }
        return res;
    }
    int dfs(int i, int j){
        if(i<0||i>=g.size()||j<0||j>=g[i].size()||g[i][j]==0){
            //cout<<"i = "<<i<<"; j = "<<j<<" returns 0"<<endl;
            return 0;
        }
        int n = g[i][j];
        g[i][j] = 0;
        auto res = max(dfs(i+1, j), max(dfs(i-1, j), max(dfs(i, j+1), dfs(i, j-1))))+n;
        g[i][j] = n;
        //cout<<"i = "<<i<<"; j = "<<j<<" returns "<<res<<endl;
        return res;
    }
};
