class Solution {
public:
    vector<vector<int>> r;
    vector<vector<int>> l;
    vector<vector<int>> d;
    vector<vector<int>> u;
    int m{};
    int n{};
    void print(const vector<vector<int>>& m){
        for(const auto& r : m){
            for(const auto& e : r){
                cout<< e <<" ";
            }
            cout<<endl;
        }
    }
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        r = grid;
        l = grid;
        u = grid;
        d = grid;
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j = n-2; j>=0; j--){
                if(grid[i][j]){
                    r[i][j] += r[i][j+1];
                }
            }
        }
        //cout<<"r"<<endl;
        //print(r);
        for(int i = 0; i<m; i++){
            for(int j = 1; j<n; j++){
                if(grid[i][j]){
                    l[i][j] += l[i][j-1];
                }
            }
        }
        //cout<<"l"<<endl;
        //print(l);
        for(int j = 0;j<n; j++){
            for(int i = 1; i<m; i++){
                if(grid[i][j]){
                    u[i][j] += u[i-1][j];
                }
            }
        }
        //cout<<"u"<<endl;
        //print(u);
        for(int j = 0;j<n; j++){
            for(int i = m-2; i>=0; i--){
                if(grid[i][j]){
                    d[i][j] += d[i+1][j];
                }
            }
        }
        //cout<<"d"<<endl;
        //print(d);
        int res{};
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int ii = i;
                int jj = j;
                if(grid[i][j]){
                    while(ii<m&&jj<n){
                        res = max(res, min({
                            r[i][j],
                            d[i][j],
                            
                            l[i][jj],
                            d[i][jj],
                            
                            u[ii][j],
                            r[ii][j],
                            
                            u[ii][jj],
                            l[ii][jj],
                            
                            ii-i+1,
                            jj-j+1
                        }));
    //cout<<"checking ("<<ii<<", "<<jj<<") for ("<<i<<", "<<j<<" )"<<" res = "<<res<<endl;
                        ii++;
                        jj++;
                    }
                }
            }
        }
        return res*res;
    }
};
