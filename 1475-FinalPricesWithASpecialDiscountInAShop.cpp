class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        prices.push_back(0);
        vector<int> res;
        for(int i = 0; i<prices.size()-1; i++){
            for(int j = i+1; j<prices.size(); j++){
                if(prices[j]<=prices[i]){
                    res.push_back(prices[i]-prices[j]);
                    break;
                }
            }
        }
        return res;
    }
};
