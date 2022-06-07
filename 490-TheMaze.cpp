class Solution {
public:
    using pii = pair<int, int>;
    bool dfs(int x, int y){
        if(x<0||y<0||x>=m||y>=n||v[x][y]) return false;
        v[x][y] = true;
        if(dst == make_pair(x, y))
            return true;
        auto d = x+1;
        auto u = x-1;
        auto l = y-1;
        auto r = y+1;
        while(r<n&&!mat[x][r]) r++;
        if(dfs(x, r-1)) return true;
        while(d<m&&!mat[d][y]) d++;
        if(dfs(d-1, y)) return true;
        while(u>=0&&!mat[u][y]) u--;
        if(dfs(u+1, y)) return true;
        while(l>=0&&!mat[x][l]) l--;
        if(dfs(x, l+1)) return true;
        return false;
    }
    pair<int, int> dst;
    vector<vector<bool>> v;
    vector<vector<int>> mat;
    int m;
    int n;
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        if(!m) return false;
        n = maze[0].size();
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        mat = maze;
        dst = make_pair(destination[0], destination[1]);
        return dfs(start[0], start[1]);
    }
};
