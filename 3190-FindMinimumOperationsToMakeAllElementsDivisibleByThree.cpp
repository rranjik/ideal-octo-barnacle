class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for(const auto& x : nums) res+=(x%3!=0);
        return res;
    }
};
