class Solution {
public:
    int m;
    int n;
    vector<vector<int>> d;
    pair<int, int> dest;
    vector<vector<int>> maze;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        if(!m)return 0;
        n = maze[0].size();
        this->maze = maze;
        d = vector<vector<int>>(m, vector<int>(n, numeric_limits<int>::max()));
        dest.first = destination[0];
        dest.second = destination[1];
        d[start[0]][start[1]] = 0;
        dfs(start[0], start[1]);
        return d[dest.first][dest.second] == numeric_limits<int>::max()?
            -1:d[dest.first][dest.second];
    }
    void dfs(int x, int y){
        for(int i = 0; i<dirs.size(); i++){
            int a = x+dirs[i][0];
            int b = y+dirs[i][1];
            int count = 0;
            while(a>=0&&b>=0&&a<m&&b<n&&!maze[a][b]){
                a += dirs[i][0];
                b += dirs[i][1];
                count++;
            }
            a-=dirs[i][0]; b-=dirs[i][1];
            if(d[x][y]+count<d[a][b]){
                d[a][b] = d[x][y]+count;
                dfs(a, b);
            }
        }
    }
};
