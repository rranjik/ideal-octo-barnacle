class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return matrix;
        int n = matrix[0].size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        vector<vector<int>> res(m, vector<int>(n, numeric_limits<int>::max()));
        using pii = pair<int, int>;
        queue<pii> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!matrix[i][j]){
                    res[i][j] = 0;
                    v[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto nn = q.front();
            q.pop();
            int i = nn.first;
            int j = nn.second;
            if(i-1>=0){
                if(!v[i-1][j]){
                    res[i-1][j] = res[i][j]+1;
                    v[i-1][j] = true;
                    q.push({i-1, j});
                }
            }
            if(j-1>=0){
                if(!v[i][j-1]){
                    res[i][j-1] = res[i][j]+1;
                    v[i][j-1] = true;
                    q.push({i, j-1});
                }
            }
            if(i+1<m){
                if(!v[i+1][j]){
                    res[i+1][j] = res[i][j]+1;
                    v[i+1][j] = true;
                    q.push({i+1, j});
                }
            }
            if(j+1<n){
                if(!v[i][j+1]){
                    res[i][j+1] = res[i][j]+1;
                    v[i][j+1] = true;
                    q.push({i, j+1});
                }
            }
        }
        return res;
    }
};
