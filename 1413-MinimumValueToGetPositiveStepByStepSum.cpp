class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minval = numeric_limits<int>::max();
        int sum = 0;
        for(const auto& n : nums){
            sum+=n;
            minval = min(minval, sum);
        }
        if(minval>0) minval = 1;
        else minval = abs(minval)+1;
        return minval;
    }
};
