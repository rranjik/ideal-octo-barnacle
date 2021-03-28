class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int m = mat.size();
        if(!m) return {};
        int n = mat[0].size();
        vector<vector<bool>> v(m, vector<bool>(n));
        vector<vector<int>> l(m, vector<int>(n));
        using pii = pair<int, int>;
        queue<pii> q;
        for(int i = 0; i<n-1; i++){
            v[m-1][i] = true;
            q.push({m-1, i});
        }
        for(int j = 0; j<m; j++){
            v[j][n-1] = true;
            q.push({j, n-1});
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            auto x = node.first; auto y = node.second;
            l[x][y]+=1;
            if(x-1>=0&&!v[x-1][y]&&mat[x-1][y]>=mat[x][y]) {
                v[x-1][y] = true;
                q.push({x-1, y});
            }
            if(x+1<m&&!v[x+1][y]&&mat[x+1][y]>=mat[x][y]) {
                v[x+1][y] = true;
                q.push({x+1, y});
            }
            if(y-1>=0&&!v[x][y-1]&&mat[x][y-1]>=mat[x][y]) {
                v[x][y-1] = true;
                q.push({x, y-1});
            }
            if(y+1<n&&!v[x][y+1]&&mat[x][y+1]>=mat[x][y]) {
                v[x][y+1] = true;
                q.push({x, y+1});
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cout<<l[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        v.clear();
        v = vector<vector<bool>>(m, vector<bool>(n));
        for(int i = 1; i<n; i++){
            v[0][i] = true;
            q.push({0, i});
        }
        for(int j = 0; j<m; j++){
            v[j][0] = true;
            q.push({j, 0});
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            auto x = node.first; auto y = node.second;
            //cout<<"x = "<<x<<"; y = "<<y<<endl;
            l[x][y]+=1;
            //if(l[x][y]>=3) cout<<" 3 @ x = "<<x<<"; y = "<<y<<endl;
            if(x-1>=0&&!v[x-1][y]&&mat[x-1][y]>=mat[x][y]) {
                v[x-1][y] = true;
                q.push({x-1, y});
            }
            if(x+1<m&&!v[x+1][y]&&mat[x+1][y]>=mat[x][y]) {
                v[x+1][y] = true;
                q.push({x+1, y});
            }
            if(y-1>=0&&!v[x][y-1]&&mat[x][y-1]>=mat[x][y]) {
                v[x][y-1] = true;
                q.push({x, y-1});
            }
            if(y+1<n&&!v[x][y+1]&&mat[x][y+1]>=mat[x][y]) {
                v[x][y+1] = true;
                q.push({x, y+1});
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cout<<l[i][j]<<" ";
            }
            cout<<endl;
        }
        vector<vector<int>> res;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(l[i][j]==2) res.push_back({i, j});
            }
        }
        return res;
    }
};
