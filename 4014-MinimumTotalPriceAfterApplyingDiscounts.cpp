class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(discounts.begin(), discounts.end());
        sort(prices.begin(), prices.end());
        reverse(discounts.begin(), discounts.end());
        reverse(prices.begin(), prices.end());
        double res = 0;
        for(int i = 0; i<discounts.size(); i++){
            if(i>=prices.size()){
                continue;
            }
            double p = prices[i];
            double d = discounts[i];
            p = p*(100-d)/100;
            res += p;
        }
        for(int i = discounts.size(); i<prices.size(); i++){
            res+=prices[i];
        }
        return res;
    }
};
