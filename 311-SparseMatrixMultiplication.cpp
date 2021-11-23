class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int Ar = A.size();
        if(!Ar) return {};
        int Ac = A[0].size();
        int Br = B.size();
        if(!Br) return {};
        int Bc = B[0].size();
        vector<vector<int>> res(Ar, vector<int>(Bc));
        for(int i = 0; i<Ar; i++){
            for(int j = 0; j<Bc; j++){
                //cout<<"A["<<i<<"]["<<j<<"]=";
                int e = 0;
                    for(int l = 0; l<Br; l++){
                        e+=A[i][l]*B[l][j];
                        //cout<<"+ A["<<i<<"]["<<l<<"]*"<<"B["<<l<<"]["<<j<<"]";
                    }
                //cout<<endl;
                res[i][j] = e;
            }
        }
        return res;
    }
};
