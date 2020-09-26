class RottenOrange{
public:
    int x;
    int y;
    int l;
    RottenOrange(int _x, int _y, int _l){
        x = _x;
        y = _y;
        l = _l;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<RottenOrange> q;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j]==2){
                    q.push(RottenOrange(i, j, 0));
                }
            }
        }
        int res = 0;
        while(!q.empty()){
            auto c = q.front();
            q.pop();
            if(c.x-1>=0&&grid[c.x-1][c.y]==1){
                grid[c.x-1][c.y] = 2;
                res = max(res, c.l+1);
                q.push(RottenOrange(c.x-1, c.y, c.l+1));
            }
            if(c.y-1>=0&&grid[c.x][c.y-1]==1){
                grid[c.x][c.y-1] = 2;
                res = max(res, c.l+1);
                q.push(RottenOrange(c.x, c.y-1, c.l+1));
            }
            if(c.y+1<grid[0].size()&&grid[c.x][c.y+1]==1){
                grid[c.x][c.y+1] = 2;
                res = max(res, c.l+1);
                q.push(RottenOrange(c.x, c.y+1, c.l+1));
            }
            if(c.x+1<grid.size()&&grid[c.x+1][c.y]==1){
                grid[c.x+1][c.y] = 2;
                res = max(res, c.l+1);
                q.push(RottenOrange(c.x+1, c.y, c.l+1));
            }
        }
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return res;
    }
};
