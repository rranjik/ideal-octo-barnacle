class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool foundOne = false;
        for(int i = 0; i<nums.size()&&!foundOne; i++){
            if(nums[i] == 1) foundOne = true;
        }
        
        if(!foundOne) return 1;
        
        int n = nums.size();
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<=0||nums[i]>n){
                nums[i] = 1;
            }
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(abs(nums[i])<n)
            nums[abs(nums[i])] = abs(nums[abs(nums[i])])*-1;
            else nums[0] = abs(nums[0])*-1;
        }
        
        for(const auto& num : nums){
            cout<<num<<" ";
        }
        cout<<endl;
        
        for(int i = 1; i<n; i++){
            if(nums[i]>0) return i;
        }
        
        if(nums[0]>0) return n;
        
        return n+1;
    }
};
