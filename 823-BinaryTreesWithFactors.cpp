class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long res = 0;
        int mod = 1e9+7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        for(int i = 0; i<arr.size(); i++){
            //one node is a tree
            dp[arr[i]] = 1;
            //anything more than i cannot possibly 
            //divide arr[i]
            for(int j = 0; j<i; j++){
                if(arr[i]%arr[j]) continue;
                dp[arr[i]] = (dp[arr[i]]+dp[arr[j]]*dp[arr[i]/arr[j]])%mod;
            }
            res = (res+dp[arr[i]])%mod;
        }
        return res;
    }
};
