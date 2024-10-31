class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for(const auto& x : nums) m[x]++;
        for(const auto& [k, v]:m) if(v&1) return false;
        return true;
    }
};
