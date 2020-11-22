class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> v;
    void dfs(int x, int y){
        if(x<0||y<0||x>=m||y>=n||v[x][y]||a[x][y]==0) return;
        v[x][y] = true;
        a[x][y] = 2;
        dfs(x-1, y);
        dfs(x+1, y);
        dfs(x, y-1);
        dfs(x, y+1);
    }
    vector<vector<int>> a;
    int shortestBridge(vector<vector<int>>& A) {
        a = A;
        m = A.size();
        n = A[0].size();
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        bool found = false;
        int x, y;
        for(int i = 0; !found&&i<m; i++){
            for(int j = 0; !found&&j<n; j++){
                if(A[i][j]) {
                    found = true;
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        dfs(x, y);
        cout<<"after conquering one island"<<endl;
        for(const auto& r : a){
            for(const auto& n : r){
                cout<<n<<" ";
            }
            cout<<endl;
        }
        cout<<"******************************"<<endl;
        
        v.clear();
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<int>> l = vector<vector<int>>(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(a[i][j]==1) {
                    v[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        
        
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            int x = e.first;
            int y = e.second;
            if(x-1>=0&&!v[x-1][y]){
                if(a[x-1][y]==2){
                    return l[x][y];
                }
                l[x-1][y] = l[x][y]+1;
                v[x-1][y] = true;
                q.push({x-1, y});
            }
            if(x+1<m&&!v[x+1][y]){
                if(a[x+1][y]==2){
                    return l[x][y];
                }
                l[x+1][y] = l[x][y]+1;
                v[x+1][y] = true;
                q.push({x+1, y});
            }
            if(y+1<n&&!v[x][y+1]){
                if(a[x][y+1]==2){
                    return l[x][y];
                }
                l[x][y+1] = l[x][y]+1;
                v[x][y+1] = true;
                q.push({x, y+1});
            }
            if(y-1>=0&&!v[x][y-1]){
                if(a[x][y-1]==2){
                    return l[x][y];
                }
                l[x][y-1] = l[x][y]+1;
                v[x][y-1] = true;
                q.push({x, y-1});
            }
        }
        return 0;
    }
};
