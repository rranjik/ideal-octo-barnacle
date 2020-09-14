class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto lbit = lower_bound(begin(nums), end(nums), target);
        if(lbit==end(nums)){
            return -1;
        }else if(*lbit>target){
            return -1;
        }else{
            return lbit-begin(nums);
        }
    }
};
