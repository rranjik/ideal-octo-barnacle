class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        multiset<int> m;
        for(int i = 0; i<nums.size(); i++){
            m.insert(nums[i]);
        }
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            res.push_back(distance(m.begin(), m.lower_bound(nums[i])));
        }
        return res;
    }
};
