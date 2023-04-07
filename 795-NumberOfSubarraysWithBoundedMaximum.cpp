class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<int> dp(A.size());
        int res{};
        int prev{-1};
        for(int i = 0; i<A.size(); i++){
            if(A[i]<L){
                if(i>0) {
                    dp[i] = dp[i-1];
                    res+=dp[i];
                }
            }else if(A[i]>R){
                prev = i;
                dp[i] = 0;
            }else {
                dp[i] = i-prev;
                res+=dp[i];
            }
        }
        return res;
    }
};
