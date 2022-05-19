class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int miss = 0;
        int prev = nums[0];
        int yet = k;
        for(int i = 1; i<nums.size(); i++){
            cout<<"miss = "<<miss<<" yet = "<<yet<<endl;
            cout<<"diff = "<<nums[i]-prev-1<<endl;
            if(nums[i]-prev>1){
                if(miss+nums[i]-prev-1>=k){
                    return nums[i-1]+yet;// -= nums[i]-prev-1;
                }else{
                    miss+=nums[i]-prev-1;
                    yet-=nums[i]-prev-1;
                }
            }
            prev=nums[i];
        }
        return nums[nums.size()-1]+yet;
    }
};
