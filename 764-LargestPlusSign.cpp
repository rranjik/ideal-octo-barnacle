class Solution {
public:
    int N;
    vector<vector<int>> L(const vector<vector<int>>& m){
        vector<vector<int>> res = vector<vector<int>>(m.size(), vector<int>(m[0].size()));
        for(int i = 0; i<m.size(); i++){
            for(int j = 0; j < m[i].size(); j++){
                if(j-1>=0){
                    if(m[i][j]) res[i][j] = res[i][j-1] + 1;
                    else res[i][j] = 0;
                } else {
                    res[i][j] = m[i][j];
                }
            }
        }
        return res;
    }
    vector<vector<int>> R(const vector<vector<int>>& m){
        vector<vector<int>> res = vector<vector<int>>(m.size(), vector<int>(m[0].size()));
        for(int i = 0; i<m.size(); i++){
            for(int j= m[0].size()-1; j>=0; j--)
                if(j+1<m[0].size()){
                    if(m[i][j]) res[i][j] = res[i][j+1]+1;
                    else res[i][j] = 0;
                } else {
                    res[i][j] = m[i][j];
                }
            }
        return res;
    }
    vector<vector<int>> U(const vector<vector<int>>& m){
        vector<vector<int>> res = vector<vector<int>>(m.size(), vector<int>(m[0].size()));
        for(int j = 0; j<N; j++){
            for(int i = 0; i<N; i++){
                if(i-1>=0){
                    if(m[i][j]) res[i][j] = res[i-1][j]+1;
                    else res[i][j] = 0;
                } else {
                    res[i][j] = m[i][j];
                }
            }
        }
        return res;
    }
    vector<vector<int>> D(const vector<vector<int>>& m){
        vector<vector<int>> res = vector<vector<int>>(m.size(), vector<int>(m[0].size()));
        for(int j = 0; j<N; j++){
            for(int i = N-1; i>=0; i--){
                if(i+1<N){
                    if(m[i][j]) res[i][j] = res[i+1][j]+1;
                    else res[i][j] = 0;
                } else{
                    res[i][j] = m[i][j];
                }
            }
        }
        return res;
    }
    void print(const vector<vector<int>>& m){
        for(int i = 0; i<m.size(); i++){
            for(int j = 0; j < m[i].size(); j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    vector<vector<int>> formFiels(int N, vector<vector<int>>& mines){
        vector<vector<int>> res = vector<vector<int>>(N, vector<int>(N, 1));
        for(int i = 0; i<mines.size(); i++){
            res[mines[i][0]][mines[i][1]] = 0;
        }
        return res;
    }
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        this->N = N;
        auto m = formFiels(N, mines);
        //print(m);
        auto l = L(m);
        cout<<"L"<<endl;;
        //print(l);
        auto r = R(m);
        cout<<"R"<<endl;;
        //print(r);
        auto u = U(m);
        cout<<"U"<<endl;;
        //print(u);
        auto d = D(m);
        cout<<"D"<<endl;;
        //print(d);
        int res = -1;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                res = max(res, min(l[i][j], min(r[i][j], min(u[i][j], d[i][j]))));
                //cout<<"res set to "<<res<<" i = "<<i <<" j = "<<j<<endl;
            }
        }
        return res;
    }
};
