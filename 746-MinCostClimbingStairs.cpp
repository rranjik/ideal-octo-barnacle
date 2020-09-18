class Solution {
public:
    unordered_map<int, int> c;
    int dp(int i){
        if(c.find(i)!=c.end()) return c[i];
        if(i>=n){
            c[i] = 0;
            return 0;
        }
        int res = cost[i] + min(dp(i+1), dp(i+2));
        c[i] = res;
        return res;
    }
    vector<int> cost;
    int n;
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        n = cost.size();
        return min(dp(0), dp(1));
    }
};
