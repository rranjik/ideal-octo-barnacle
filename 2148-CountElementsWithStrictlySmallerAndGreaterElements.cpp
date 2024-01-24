class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = -1;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]!=nums[i+1]){
                start = i+1;
                break;
            }
        }
        if(start==-1) return 0;
        int end = -1;
        for(int i = nums.size()-1; i>0; i--){
            if(nums[i]!=nums[i-1]){
                end = i-1;
                break;
            }
        }
        if(end==-1) return 0;
        return end-start+1;
    }
};
