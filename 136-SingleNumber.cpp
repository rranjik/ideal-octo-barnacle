class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int accum = 0;
        for(const auto& n : nums){
            accum ^= n;
        }
        return accum;
    }
};
