class Solution {
public:
    void dfs(int x, int y, int& s, bool& r){
        if(x<0||y<0||x>=m||y>=n||!a[x][y]||v[x][y]) return;
        s++;
        v[x][y] = true;
        if(x==0||x==m-1||y==0||y==n-1) r = true;
        dfs(x+1, y, s, r);
        dfs(x-1, y, s, r);
        dfs(x, y+1, s, r);
        dfs(x, y-1, s, r);
    }
    vector<vector<int>> a;
    vector<vector<bool>> v;
    int m{};
    int n{};
    int numEnclaves(vector<vector<int>>& A) {
        this->a = A;
        m = a.size();
        if(!m) return 0;
        n = a[0].size();
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        int res{};
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(a[i][j]&&!v[i][j]){
                    bool r = false;
                    int s = 0;
                    dfs(i, j, s, r);
                    if(!r) res+=s;
                }
            }
        }
        return res;
    }
};
