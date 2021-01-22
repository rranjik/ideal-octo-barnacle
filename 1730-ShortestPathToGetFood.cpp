class Solution {
public:
    
    int getFood(vector<vector<char>>& grid) {
        int l{};
        queue<pair<int, int>>q;
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1},{-1, 0}};
        int m = grid.size();    
        int n = grid[0].size();    
        vector<vector<bool>> v = vector<vector<bool>>(m, vector<bool>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='*') {
                    v[i][j] = true;
                    q.push({i, j});
                    break;
                }
            }
        }
        while(!q.empty()){
            l++;
            int s = q.size();
            for(int i = 0; i<s; i++){
                auto f = q.front(); q.pop();
                //cout<<"removing "<<f.first<<", "<<f.second<<endl;
                for(int j = 0; j<dir.size(); j++){
                    auto nx = f.first+dir[j][0];
                    auto ny = f.second+dir[j][1];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&!v[nx][ny]&&grid[nx][ny]!='X'){
                        if(grid[nx][ny]=='#') return l;
                        v[nx][ny] = true;
                        //cout<<"adding "<<nx<<", "<<ny<<endl;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};
