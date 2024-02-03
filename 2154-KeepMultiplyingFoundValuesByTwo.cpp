class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s;
        for(int i = 0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        while(s.find(original)!=s.end()){
            original*=2;
        }
        return original;
    }
};
