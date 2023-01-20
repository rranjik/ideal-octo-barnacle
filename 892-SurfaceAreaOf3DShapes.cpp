class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(); if(!n) return 0; int m = grid[0].size();
        int res{};
        int s{};
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(i-1>=0){
                    res+=abs(grid[i-1][j]-grid[i][j]);
                }else{
                    s+=grid[i][j];
                }
                if(i+1<n){
                    res+=abs(grid[i+1][j]-grid[i][j]);
                }else{
                    s+=grid[i][j];
                }
                if(j+1<n){
                    res+=abs(grid[i][j+1]-grid[i][j]);
                }else{
                    s+=grid[i][j];
                }
                if(j-1>=0){
                    res+=abs(grid[i][j]-grid[i][j-1]);
                }else{
                    s+=grid[i][j];
                }
                if(grid[i][j]) s+=2;
            }
        }
        return res/2+s;
    }
};
