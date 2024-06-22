class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int lo1 = prices[0]; int lo2 = prices[1];
        if(money-lo1-lo2<0) return money;
        return money-lo1-lo2;
    }
};
