class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0;
        int j = 0;
        int nz = 0;
        int k = K;
        int res{};
        while(j<A.size()){
            if(!A[j]) nz++;
            while(nz>k){
                if(A[i]==0){
                    nz--;
                }
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
