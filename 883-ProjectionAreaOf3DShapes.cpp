class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> side(n, 0);
        vector<int> front(n, 0);
        auto top{0};
        auto res{0};
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                side[i] = max(side[i], grid[i][j]);
                if(grid[i][j]) top++;
            }
            res+=side[i];
        }
        for(int j = 0; j<grid.size(); j++){
            for(int i = 0; i<grid[0].size(); i++){
                front[j] = max(front[j], grid[i][j]);
            }
            res+=front[j];
        }
        res+=top;
        return res;
    }
};
