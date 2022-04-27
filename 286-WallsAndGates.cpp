class Solution {
public:
    int m;
    int n;
    void bfs(vector<pair<int, int>> starts, vector<vector<int>>& rooms){
        queue<pair<int, int>> q;
        vector<vector<bool>> v(m, vector<bool>(n, false));
        for(const auto& p : starts)
            q.push(p);
        while(!q.empty()){
            auto c = q.front();
            v[c.first][c.second] = true;
            q.pop();
            //up
            if(c.first-1>=0&&!v[c.first-1][c.second]
              &&rooms[c.first-1][c.second]!=-1){
                if(rooms[c.first-1][c.second]>rooms[c.first][c.second]+1){
                rooms[c.first-1][c.second]= rooms[c.first][c.second]+1; 
                q.push(make_pair(c.first-1, c.second));
              }
            }
            //down
            if(c.first+1<m&&!v[c.first+1][c.second]
              &&rooms[c.first+1][c.second]!=-1){
                if(rooms[c.first+1][c.second]>rooms[c.first][c.second]+1){
                rooms[c.first+1][c.second] = rooms[c.first][c.second]+1, 
                q.push(make_pair(c.first+1, c.second));
                }
            }
            //left
            if(c.second-1>=0&&!v[c.first][c.second-1]
              &&rooms[c.first][c.second-1]!=-1){
                if(rooms[c.first][c.second-1]>rooms[c.first][c.second]+1){
                rooms[c.first][c.second-1] = rooms[c.first][c.second]+1, 
                q.push(make_pair(c.first, c.second-1));
                }
            }
            //right
            if(c.second+1<n&&!v[c.first][c.second+1]
              &&rooms[c.first][c.second+1]!=-1){
                if(rooms[c.first][c.second+1]>rooms[c.first][c.second]+1){
                rooms[c.first][c.second+1] = rooms[c.first][c.second]+1, 
                q.push(make_pair(c.first, c.second+1));
                }
            }
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        if(!m) return;
        n = rooms[0].size();
        vector<pair<int , int>> starts;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(rooms[i][j]==0){
                    starts.push_back(make_pair(i, j));
                }
            }
        }
        bfs(starts, rooms);
    }
};
