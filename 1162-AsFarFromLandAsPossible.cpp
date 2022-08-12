class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        using pii = pair<int, int>;
        queue<pii> q;
        int n = grid.size();
        if(!n) return -1;
        int m = grid[0].size();
        vector<vector<bool>> v = vector<vector<bool>>(n, vector<bool>(m));
        vector<vector<int>> dist = vector<vector<int>>(n, vector<int>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]) {
                    v[i][j] = true;
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        vector<pii> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int res{};
        while(!q.empty()){
            auto fc = q.front();
            q.pop();
            for(const auto& p : d){
                auto f = fc;
                f.first+=p.first;
                f.second+=p.second;
                if(0<=f.first&&
                   f.first<n&&
                   0<=f.second&&
                   f.second<m&&
                   !v[f.first][f.second]){
                    q.push({f.first, f.second});
                   dist[f.first][f.second] = dist[fc.first][fc.second]+1;
                   v[f.first][f.second] = true;
                    cout<<"adding ("<<f.first<<", "<<f.second<<
                        ") at "<<dist[f.first][f.second]<<endl;
                    res = max(res,dist[f.first][f.second]);
                }
            }
            
        }
        return res?res:-1;
    }
};
