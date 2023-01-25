class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        auto res = 0;
        for(const auto& p : accounts){
            auto w = 0;
            for(const auto& b : p){
                w+=b;
            }
            res = max(res, w);
        }
        return res;
    }
};
