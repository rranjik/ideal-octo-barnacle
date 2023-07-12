class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int m = p.size();
        int n = p[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        //precompute first row, copy from input; because 
        //no jumping, we can start at any column that we want
        //i.e, no penalty incurred
        for(int i = 0; i<n; i++){
            dp[0][i] = p[0][i];
        }
        for(int i = 1; i<m; i++){
            vector<long long> L(n, -1);
            vector<long long> R(n, -1);
            
            L[0] = dp[i-1][0];
            for(int k = 1; k<n; k++){
                //as long as the previous location dominates 
                //use it
                //when it gets overwhelmed by the one above
                //start using that instead
                //0 1   2 ... k    
                //x big x x x here x x x 
                //x x   x x x L[k] 
                //if big is really big then it might 
                //be really worth taking it if not just 
                //take the one above you (here)
                
                //note: the k component of penalty when an 
                //element is taken from  the left is 
                //independent of who takes it
                
                //that is, we can think of this as contribution 
                //to the right
                
                //0 1 2 3 4
                //. . . . x . . . . 
                //when is x is taken by some element on the right
                //its +4 component of penalty is always the same 
                //because x is in column 4
                
                //(but there will be an additional penalty of who
                //on the right picks it up - the j component of 
                //penalty)
                L[k] = max(L[k-1], dp[i-1][k]+k);
            }
            
            //column contributions of last elem is (n-1)
            R[n-1] = dp[i-1][n-1] - (n-1);
            for(int k = n-2; k>=0; k--){
                R[k] = max(R[k+1], dp[i-1][k]-k);
            }
            
            //apply j component of penalty after picking up
            //from left or from the right
            for(int j = 0; j<n; j++){
                dp[i][j] = max(L[j]-j, R[j]+j) + p[i][j];
            }
        }
        for(const auto& r : dp){
            for(const auto& n : r){
                cout<<n<<" ";
            }
            cout<<endl;
        }
        long long res = -1;
        for(int i = 0; i<n; i++){
            res = max(res, dp[m-1][i]);
        }
        return res;
    }
};
