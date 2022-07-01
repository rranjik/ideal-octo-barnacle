class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()>1){
            int n = nums.size();
            vector<int> nn(n/2);
            for(int i = 0; i<n/2; i++){
                if(i%2){
                    nn[i] = max(nums[2*i], nums[2*i+1]);
                }else{
                    nn[i] = min(nums[2*i], nums[2*i+1]);
                }
            }
            swap(nums, nn);
        }
        return nums[0];
    }
};
