class Solution {
public:
    void print(const vector<vector<int>>& v){
        for(const auto& r : v){
            for(const auto& n : r){
                //cout<<n<<" ";
            }
            //cout<<endl;
        }
    }
    void dfs(int i, int j, const vector<vector<int>>& g, const int& ccn, vector<vector<int>>& gc, vector<vector<int>>& p, vector<vector<bool>>& v){
        //cout<<"i = "<<i<<" j = "<<j<<endl;
        if(i>=m||i<0||j>=n||j<0) return;
        if(!g[i][j])
            return;
        if(v[i][j]) return;
        v[i][j] = true;
        p.push_back({i, j});
        gc[i][j] = ccn;
        dfs(i+1, j, g, ccn, gc, p, v);
        dfs(i-1, j, g, ccn, gc, p, v);
        dfs(i, j+1, g, ccn, gc, p, v);
        dfs(i, j-1, g, ccn, gc, p, v);
    }
    int m{};
    int n{};
    vector<vector<bool>> v1;
    vector<vector<bool>> v2;
    vector<vector<int>> g1c;
    vector<vector<int>> g2c;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        if(!m) return 0;
        n = grid1[0].size();
        g1c = grid1;
        g2c = grid2;
        v1 = vector<vector<bool>>(m, vector<bool>(n));
        v2 = vector<vector<bool>>(m, vector<bool>(n));
        int ccn = 2;
        //cout<<"m = "<<m<<" n = "<<n<<endl;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!v1[i][j]&&grid1[i][j]){
                    vector<vector<int>> p;
                    dfs(i, j, grid1, ccn, g1c, p, v1);
                    //cout<<"island size "<<p.size()<<endl;
                    ccn++;
                    //print(g1c);
                }
            }
        }
        //cout<<"g1 has "<<ccn-2<<" components "<<endl;
        int res{};
        ccn = 2;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!v2[i][j]&&grid2[i][j]){
                    vector<vector<int>> p;
                    dfs(i, j, grid2, ccn, g2c, p, v2);
                    //cout<<"island size "<<p.size()<<endl;
                    ccn++;
                    int last = -1;
                    auto same = true;
                    for(int k = 0; k<p.size(); k++){
                        auto c = g1c[p[k][0]][p[k][1]];
                        if(last<0){
                            last = c;
                        }else{
                            if(last!=c) {
                                same = false;
                                break;
                            }
                        }
                    }
                    if(same&&last>0) res++;
                    //print(g2c);
                }
            }
        }
        //cout<<"g2 has "<<ccn-2<<" components "<<endl;
        return res;
    }
};
