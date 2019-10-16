class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        unordered_map<int, int> f;
        for(int i = 0; i<nums.size(); i++){
            if(f.find(nums[i])!=f.end()){
                if(i-f[nums[i]]<=k)
                    return true;
            }
            f[nums[i]] = i;
        }
        return false;
    }
};
