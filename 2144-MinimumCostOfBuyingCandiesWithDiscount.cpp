class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        int res = 0;
        for(int i = 0; i<cost.size(); i++){
            res += cost[i];
            if(i+1<cost.size()) 
                res+=cost[++i];
            i++;
        }
        return res;
    }
};
