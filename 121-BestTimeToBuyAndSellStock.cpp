class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int b = numeric_limits<int>::max();
        for(const auto& p : prices){
            b = min(b, p);
            res = max(res, p -b);
        }
        return res;
    }
};
