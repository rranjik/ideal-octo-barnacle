class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> f;
        for(const auto& n : nums){
            f[n]++;
        }
        int res{};
        for(const auto& it : f){
            if(it.second==1) res+=it.first;
        }
        return res;
    }
};
