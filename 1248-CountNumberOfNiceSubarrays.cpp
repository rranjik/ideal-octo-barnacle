class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i{}, count{}, res{};
        for(int j = 0; j<nums.size(); j++){
            if(nums[j]%2){
                k--;
                count = 0;
            }
            while(!k){
                if(nums[i]%2) k++;
                count++;
                i++;
            }
            res+=count;
        }
        return res;
    }
};
