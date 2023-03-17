class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            vector<int> nn;
            for(int j = 0; j<n; j++){
                nn.push_back(nums[i]);
                i = (i+1)%n;
            }
            if(is_sorted(nn.begin(), nn.end())) return true;
        }
        return false;
    }
};
