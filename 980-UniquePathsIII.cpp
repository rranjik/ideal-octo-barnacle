class Solution {
public:
    int dfs(int i, int j, int s, vector<vector<int>>& g){
        if(i<0||j<0||i>=g.size()||j>=g[i].size()||g[i][j]==-1)
            return 0;
        if(g[i][j]==2){
            if(s == target) return 1;
            else return  0;
        }
        g[i][j] = -1;
        int p = dfs(i+1, j, s+1, g) + dfs(i, j+1, s+1, g)+
            dfs(i-1, j, s+1, g) + dfs(i, j-1, s+1, g);
        g[i][j] = 0;
        return p;
    }
    int target = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x = 0; 
        int y = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    x = i;
                    y = j;
                }
                if(grid[i][j] != -1) 
                    target++;
            }
        }
        cout<<"target = "<<target<<endl;
        return dfs(x, y, 1, grid);
    }
};
