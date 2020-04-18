class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> ii;
        for(int i = 0; i<A.size(); i++){
            ii[A[i]] = i;
        }
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
        int res = 0;
        for(int i = 0; i<A.size(); i++){
            for(int j = i+1; j<A.size(); j++){
                int p = A[j]-A[i];
                if((ii.find(p)!=ii.end())&&((ii[p]!=i)&&(ii[p]!=j))&&(ii[p]<i)){
                    dp[i][j] = dp[ii[p]][i]+1;
                    res = max(res, dp[i][j]);
                }
            }
        } 
        //for(int i = 0; i<A.size(); i++){
        //    for(int j = 0; j<A.size(); j++){
        //        cout<<dp[i][j]<<" ";
        //    }
        //    cout<<endl;
        //}
        //return res;
        return res>=1?res+2:0;
    }
};
