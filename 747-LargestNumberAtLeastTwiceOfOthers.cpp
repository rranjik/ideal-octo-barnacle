class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end());
        auto m = *it;
        for(const auto& n : nums){
            if(n!=m&&m<2*n) return -1;
        }
        return it-nums.begin();
    }
};
