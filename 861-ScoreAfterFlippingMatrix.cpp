class Solution {
public:
    void flipr(vector<vector<int>>& A, int r){
        for(auto& n : A[r]){
            if(n) n = 0;
            else n = 1;
        }
    }
    void flipc(vector<vector<int>>& A, int c){
        for(int i = 0; i<A.size(); i++){
            if(A[i][c]) A[i][c] = 0;
            else A[i][c] = 1;
        }
    }
    int countc(const vector<vector<int>>& A, int c){
        int res = 0;
        for(int i = 0; i<A.size(); i++){
            res+=A[i][c];
        }
        return res;
    }
    int matrixScore(vector<vector<int>>& A) {
        for(int i = 0; i<A.size(); i++){
            if(!A[i][0]) flipr(A, i);
        }
        for(int i = 0; i<A[0].size(); i++){
            int noones = countc(A, i);
            int nozeros = A.size()-noones;
            if(noones<nozeros) flipc(A, i);
        }
        int res = 0;
        for(int i = 0; i<A.size(); i++){
            for(int j = 0; j<A[0].size(); j++){
                cout<<pow(2, A.size()-1-i)<<" ";
                res+=(A[i][j]*pow(2, A[0].size()-1-j));
            }
            cout<<endl;
        }
        for(const auto& r : A){
            for(const auto& n : r){
                cout<<n<<" ";
            }
            cout<<endl;
        }
        return res;
    }
};
