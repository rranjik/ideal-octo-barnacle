class Solution {
public:
    struct node{
        int d{}; int i{}; int j{};
        node(int _d, int _i, int _j):d(_d), i(_i), j(_j){}
        bool operator<(const node& n) const {
            return d>n.d;
        }
    };
    vector<int> dir{0, 1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<node> q;
        q.push(node(0, 0, 0));
        int m = h.size();
        int n = h[0].size();
        vector<vector<int>> v(m, vector<int>(n, numeric_limits<int>::max()));
        vector<vector<bool>> visited(m, vector<bool>(n));
        while(!q.empty()){
            auto k = q.top();q.pop();
            int d = k.d;
            int r = k.i;
            int c = k.j;
            //if(visited[r][c]) continue;
            //visited[r][c] = true;
            if(r==m-1&&n-1==c) return d;
            for(int i = 0; i<4; i++){
                auto nr = r+dir[i];
                auto nc = c+dir[i+1];
                if(nr>=0&&nc>=0&&nr<m&&nc<n){
                    auto nd = max(d, abs(h[r][c]-h[nr][nc]));
                    if(v[nr][nc]>nd){
                        v[nr][nc] = nd;
                        q.push(node(nd, nr, nc));
                    }
                }
            }
        }
        return 0;
    }
};
