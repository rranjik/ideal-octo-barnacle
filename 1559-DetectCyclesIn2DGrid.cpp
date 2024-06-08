class Solution {
public:
    bool dfs(int i, int j, int ip, int jp){
        //cout<<"i = "<<i<<" j = "<<j<<" ip = "<<ip<<" jp = "<<jp<<endl;
        if(v[i][j]) return true;
        v[i][j] = true;
        for(const auto& d : dir){
            int rr = d[0]+i;
            int cc = d[1]+j;
            //cout<<"rr = "<<rr<<" cc = "<<cc<<endl;
            if(rr==ip&&cc==jp) continue;
            if(rr>=0&&
               rr<m&&
               cc>=0&&
               cc<n&&
               g[rr][cc]==g[i][j]){
                if(dfs(rr, cc, i, j)) return true;
            }
        }
        return false;
    }
    vector<vector<char>> g;
    vector<vector<bool>> v;
    int m; int n;
    vector<vector<int>> dir = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };
    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        m = g.size();
        n = g[0].size();
        cout<<"m = "<<m<<" n = "<<n<<endl;
        v = vector<vector<bool>> (m, vector<bool>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!v[i][j]){
                    if(dfs(i, j, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};
