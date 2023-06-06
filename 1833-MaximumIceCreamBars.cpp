class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int res{};
        for(int i = 0; i<costs.size(); i++){
            if(coins>=costs[i]){
                coins-=costs[i];
                res++;
            }else return res;
        }
        return res;
    }
};
