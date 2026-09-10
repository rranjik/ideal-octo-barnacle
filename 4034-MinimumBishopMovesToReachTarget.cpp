class Solution {
public:
    bool inrange(int x, int y){
        if(x>=0 && x<8 && y>=0 && y<8) return true;
        return false;
    }
    void print(const vector<vector<int>>& b){
        for(const auto& r : b){
            for(const auto& x : r){
                cout<<setw(3)<<x<<" ";
            }
            cout<<endl;
        }
    }
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        queue<pair<int, int>> q;
        q.push({source[0]-1, source[1]-1});
        vector<vector<int>> b(8, vector<int>(8, -1));
        b[source[0]-1][source[1]-1] = 0;
        vector<pair<int, int>> dirs = {
            {-1, 1},
            {1, 1},
            {-1, -1},
            {1, -1}
        };
        int tx = target[0]-1;
        int ty = target[1]-1;
        int level = 1;
        while(!q.empty()){
            int sz = q.size();
            queue<pair<int, int>> nq;
            for(int i = 0; i<sz; i++){
                auto [x, y] = q.front(); q.pop();
                for(const auto& [dx, dy] : dirs) {
                    int nx = x+dx; int ny = y+dy;
                    while(inrange(nx, ny)){
                        if(b[nx][ny]==-1) {
                            b[nx][ny] = level;
                            if((nx==tx)&&(ny==ty)) return level;
                            else nq.push({nx, ny});
                        }
                        nx+=dx; ny+=dy;
                    }
                }     
            }
            print(b);
            cout<<endl;
            level++;
            q = nq;
        }
        return -1;
    }
};

