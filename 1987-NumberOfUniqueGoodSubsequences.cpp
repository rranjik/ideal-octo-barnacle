class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod = 1e9+7;
        vector<int> dp = {0, 0};
        for(const auto& c : binary){
            //end bit
            int ebit = c-'0';
            dp[ebit] = (dp[0]+dp[1]+(ebit?1:0)) % mod;
        }
        return (dp[0]+dp[1]+(binary.find("0")!=string::npos))%mod;
    }
};
