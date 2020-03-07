class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]] = i;
        }
        for(int i = 0; i<nums.size(); i++){
            if(m.find(target-nums[i])!=m.end()&&m[target-nums[i]]!=i){
                res.push_back(i);
                res.push_back(m[target-nums[i]]);
                return res;
            }
        }
        return res;
    }
};
