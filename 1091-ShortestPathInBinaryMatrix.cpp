class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        queue<pair<int, int>> q;
        int m  = g.size();
        int n = g[0].size();
        if(g[0][0]!=0) return -1;
        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        q.push({0, 0});
        int level = 1;
        vector<vector<bool>> v(m, vector<bool>(n));
        v[0][0] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                auto [x, y] = q.front(); q.pop();
                if(x==m-1&&y==n-1) return level;
                for(const auto& [dx, dy] : dirs){
                    auto nx = x+dx;
                    auto ny = y+dy;
                    if(nx<0||nx>=m||ny<0||ny>=n||
                        (g[nx][ny]!=0)||(v[nx][ny])) 
                        continue;
                    q.push({nx, ny});
                    v[nx][ny] = true;
                }
            }
            level++;
        }
        return -1;
    }
};
