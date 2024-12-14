class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        queue<pair<pair<int, int>, pair<int, int>>> q;
        vector<vector<char>> g(m, vector<char>(n, 'e'));
        vector<vector<bool>> v(m, vector<bool>(n));
        for(const auto& p : guards){
            q.push({{p[0], p[1]}, {1, 0}});
            q.push({{p[0], p[1]}, {-1, 0}});
            q.push({{p[0], p[1]}, {0, 1}});
            q.push({{p[0], p[1]}, {0, -1}});
            g[p[0]][p[1]] = 'g';
            v[p[0]][p[1]] = true;
        }
        for(const auto& p : walls){
            g[p[0]][p[1]] = 'w';
            v[p[0]][p[1]] = true;
        }
        while(!q.empty()){
            auto gd = q.front(); q.pop();
            auto [x, y] = gd.first;
            auto [dx, dy] = gd.second;
            auto xx = x+dx;
            auto yy = y+dy;
            if(xx>=0&&xx<m&&yy>=0&&yy<n&&g[xx][yy]!='g'&&g[xx][yy]!='w'){
                q.push({{xx, yy}, {dx, dy}});
                v[xx][yy] = true;
            }
        }
        int res = 0;
        for(const auto& r : v){
            for(const auto& c : r){
                if(!c) res++;
            }
        }   
        return res;
    }
};
