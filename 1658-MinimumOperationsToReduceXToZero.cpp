class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum{};
        for(const auto& n : nums) sum+=n;
        if(sum<x) return -1;
        if(sum==x) return nums.size();
        //last seen
        //prefix-sum -> where was it last seen
        unordered_map<int, int> ls;
        int prefix{};
        ls[0] = -1;
        int target = sum-x;
        int res = -1;
        for(int i = 0; i<nums.size(); i++){
            prefix = prefix+nums[i];
            if(ls.find(prefix-target)!=ls.end()) res = max(res, i-ls[prefix-target]);
            ls[prefix] = i;
        }
        return res==-1?-1:nums.size()-res;
    }
};
