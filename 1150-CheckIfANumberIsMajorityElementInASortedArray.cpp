class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 0;
        int candidate = -1;
        for(int i = 0; i<nums.size(); i++){
            if(count==0){
                candidate= nums[i];
                count++;
            }else {
                if(candidate == nums[i]) count++;
                else count--;
            }
        }
        cout<<"candidate = "<<candidate<<endl;
        auto lb = lower_bound(begin(nums), end(nums), target);
        auto ub = upper_bound(begin(nums), end(nums), target);
        return candidate == target&&(distance(lb, ub)>nums.size()/2);
    }
};
