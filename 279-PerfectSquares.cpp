class Solution {
public:
    vector<int> choices;
    unordered_map<int, int> cache;
    int dp(int n) {
        if(cache.find(n)!=cache.end())
            return cache[n];
        if(n==0){
            cache[0] = 0;
            return cache[n];
        }
        int res = numeric_limits<int>::max();
        for(int i = 0; i<choices.size(); i++){
            if(choices[i]<=n){
                res = min(res, dp(n-choices[i])+1);
            }
        }
        cache[n] = res;
        return cache[n];
    }
    int numSquares(int n) {
        int s = sqrt(n);
        for(int i = 1; i<=s; i++){
            choices.push_back(i*i);
        }
        return dp(n);
    }
};
