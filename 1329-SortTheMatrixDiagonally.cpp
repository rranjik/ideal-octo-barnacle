class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(!mat.size()) return mat;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = m-1; i>=-(n-1); i--){
            //if(i>=0){
                int li = abs(i); int ri = 0;
                if(i<0) swap(li, ri);
                int sr = li; int er = ri;
                vector<int> diag;
                while(sr<m&&er<n){
                    diag.push_back(mat[sr][er]);
                    sr++;
                    er++;
                }
                for(const auto& e : diag)
                    cout<<e<<" ";
                cout<<endl;
                sort(begin(diag), end(diag));
                sr = li; er = ri;
                for(const auto& e : diag){
                    mat[sr][er] = e;
                    sr++;er++;
                }
            //}
        }
        return mat;
    }
};
