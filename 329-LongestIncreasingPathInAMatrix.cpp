class Solution {
public:
    const int inf = numeric_limits<int>::min();
    int dfs(int x, int y, const vector<vector<int>>& m){
        //cout<<"x = "<<x<<"; y = "<<y<<endl;
        if(x<0||y<0||x>=p||y>=n) return 0;
        if(c[x][y]!=-1) return c[x][y];
        int res = 0;
        if(x-1>=0){
            if(m[x-1][y]>m[x][y]){
                //auto old = m[x][y];
                //m[x][y] = inf;
                res = max(res, dfs(x-1, y, m)+1);
                //m[x][y] = old;
            }
        }
        if(x+1<p){
            if(m[x+1][y]>m[x][y]){
                //auto old = m[x][y];
                //m[x][y] = inf;
                res = max(res, dfs(x+1, y, m)+1);
                //m[x][y] = old;
            }
        }
        if(y-1>=0){
            if(m[x][y-1]>m[x][y]){
                //auto old = m[x][y];
                //m[x][y] = inf;
                res = max(res, dfs(x, y-1, m)+1);
                //m[x][y] = old;
            }
        }
        if(y+1<n){
            if(m[x][y+1]>m[x][y]){
                //auto old = m[x][y];
                //m[x][y] = inf;
                res = max(res, dfs(x, y+1, m)+1);
                //m[x][y] = old;
            }
        }
        c[x][y] = res;
        return res;
    }
    int p;
    int n;
    vector<vector<int>> c;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        p = matrix.size();
        if(!p) return 0;
        n = matrix[0].size();
        int res = 0;
        c = vector<vector<int>>(p, vector<int>(n, -1));
        for(int i = 0; i<p; i++){
            for(int j = 0; j<n; j++){
                res = max(res, dfs(i, j, matrix)+1);
            }
        }
        return res;
    }
};
