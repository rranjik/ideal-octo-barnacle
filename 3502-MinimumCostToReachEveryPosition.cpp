class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> res;
        int m = 101;
        for(int i = 0; i<cost.size(); i++){
            m = min(m, cost[i]);
            res.push_back(m);
        }
        return res;
    }
};
