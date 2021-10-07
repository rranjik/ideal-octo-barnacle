class Solution {
public:
    int dp(int i, int j){
        if(i<0||j<0) return 0;
        if(c[i][j]!=-1) return c[i][j];
        int res = 0;
        res = max(res, dp(i-1, j));
        //because j could change within
        //the function before we return
        auto ci{i}, cj{j};
        while(i>=0&&j>=0){
            if(A[i]==B[j]){
                //cout<<"i = "<<i<<" and j = "<<j<<" match "<<endl;
                res = max(res, dp(i-1, j-1)+1);
                break;
            }
            j--;
        }
        //need original i and j here
        c[ci][cj] = res;
        return res;
    }
    vector<int> A;
    vector<int> B;
    vector<vector<int>> c;
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        this->A = A;
        this->B = B;
        c = vector<vector<int>>(A.size(), vector<int>(B.size(), -1));
        return dp(A.size()-1, B.size()-1);
    }
};
