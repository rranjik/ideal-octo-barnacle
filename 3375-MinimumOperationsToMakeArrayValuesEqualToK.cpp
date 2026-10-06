class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<k) return -1;
        }
        set<int> s(nums.begin(), nums.end());
        s.erase(k);
        return s.size();
    }

};
