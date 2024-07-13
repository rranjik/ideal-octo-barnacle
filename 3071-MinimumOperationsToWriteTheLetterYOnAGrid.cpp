class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& g) {
        vector<int> y(3);
        vector<int> v(3);
        int n = g[0].size();
        unordered_map<int, unordered_map<int, bool>> iny;
        for(int i = 0, j = 0; i<=n/2; i++, j++){
            cout<<"counting "<<i<<" "<<j<<endl;
            iny[i][j] = true;
            y[g[i][j]]++;
        }
        for(const auto& c : y) cout<<c<<" "; cout<<endl;
        cout<<"**"<<endl;
        for(int i = 0, j = n-1; i<n/2; i++, j--){
            cout<<"counting "<<i<<" "<<j<<" "<<g[i][j]<<endl;
            iny[i][j] = true;
            y[g[i][j]]++;
        }
        for(const auto& c : y) cout<<c<<" "; cout<<endl;
        cout<<"**"<<endl;
        for(int k = n/2+1; k<n; k++){
            cout<<"counting "<<k<<" "<<n/2<<endl;
            iny[k][n/2] = true;
            y[g[k][n/2]]++;
        }
        for(const auto& c : y) cout<<c<<" "; cout<<endl;
        cout<<"**"<<endl;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(!iny[i][j]){
                    cout<<"counting "<<i<<" "<<j<<endl;
                    v[g[i][j]]++;
                }
            }
        }
        for(const auto& c : v) cout<<c<<" "; cout<<endl;
        int rres = n*n;
        for(const auto& yv : {0, 1, 2}){
            for(const auto& vv : {0, 1, 2}){
                if(yv==vv) continue;
                int res = 0;
                for(int i = 0; i<3; i++){
                    if(i!=yv)  res+= y[i];
                }
                for(int i = 0; i<3; i++){
                    if(i!=vv)  res+= v[i];
                }
                rres = min(res, rres);
            }
        }
        return rres;
    }
};
