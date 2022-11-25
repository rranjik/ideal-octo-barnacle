class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> p;
        for(int i = 0; i<nums.size(); i++){
            p[nums[i]]++;
        }
        int res{};
        for(int i = 0; i<nums.size(); i++){
            if(p.find(nums[i]+1)!=p.end())
                res = max(res, p[nums[i]]+p[nums[i]+1]);
            if(p.find(nums[i]-1)!=p.end())
                res = max(res, p[nums[i]]+p[nums[i]-1]);
        }
        return res;
    }
};
