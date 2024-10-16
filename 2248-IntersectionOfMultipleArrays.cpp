class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> f;
        int r = nums.size();
        for(const auto& arr: nums){
            for(const auto& a : arr){
                f[a]++;
            }
        }
        set<int> s;
        for(const auto& [n, k]:f){
            if(k==r) s.insert(n);
        }
        return {s.begin(), s.end()};
    }
};
