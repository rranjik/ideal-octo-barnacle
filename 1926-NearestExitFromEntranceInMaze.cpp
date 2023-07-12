class Solution {
public:
    vector<vector<int>> d;
    vector<vector<int>> v;
    bool isExit(const pair<int, int>& e, const pair<int, int>& loc){
        if(loc==e) return false;
        if(loc.first-1<0) return true;
        if(loc.first+1>=m) return true;
        if(loc.second-1<0) return true;
        if(loc.second+1>=n) return true;
        return false;
    }
    int m = 0;
    int n = 0;
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        m = maze.size();
        n = maze[0].size();
        d = vector<vector<int>>(m, vector<int>(n, 1e9+7));
        v = vector<vector<int>>(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({e[0], e[1]});
        vector<vector<int>> dir = {
            {1, 0}, //down
            {-1, 0}, //up
            {0, 1}, //right
            {0, -1} //left
        };
        
        int l = 0;
        d[e[0]][e[1]] = 0;
        v[e[0]][e[1]] = 1;
        while(!q.empty()){
            for(int k = 0; k<q.size(); k++){
                auto loc = q.front(); q.pop();
                auto r = loc.first; auto c = loc.second;
                cout<<"r = "<<r<<" c = "<<c<<endl;
                if(isExit({e[0], e[1]}, loc)) return d[r][c];
                for(int i = 0; i<dir.size(); i++){
                    auto nr = r+dir[i][0];
                    auto nc = c+dir[i][1];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&!v[nr][nc]&&maze[nr][nc]=='.'){
                        d[nr][nc] = d[r][c]+1;
                        v[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
