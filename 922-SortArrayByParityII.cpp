class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<int> res(A.size());
        int o = 1;
        int e = 0;
        for(int i = 0; i<A.size(); i++){
            if(A[i]%2){
                res[o] = A[i];
                o+=2;
            }else {
                res[e] = A[i];
                e+=2;
            }
        }
        return res;
    }
};
