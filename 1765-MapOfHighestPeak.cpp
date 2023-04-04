class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& g) {
        queue<pair<int, int>> q;
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n));
        vector<vector<bool>> v = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(g[i][j]==1){
                    v[i][j] = true;
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            auto s = q.size(); 
            for(int i = 0; i<s; i++){
                auto f = q.front(); q.pop();
                auto r = f.first; auto c = f.second;
                //cout<<"looking at "<<r<<", "<<c<<endl;
                for(const auto& d : dir){
                    auto nr = d[0] + r;
                    auto nc = d[1] + c;
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&!v[nr][nc]){
                        v[nr][nc] = true;
                        res[nr][nc] = res[r][c]+1;
                        //cout<<" pushing at "<<nr<<", "<<nc<<endl;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return res;
    }
};
