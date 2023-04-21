class Solution {
public:
    int zigzag(vector<int> nums, bool less){
        int res = 0;
        for(int i = 0; i<nums.size()-1; i++){
            if(less){
                if(nums[i]>=nums[i+1]){
                    res+= (nums[i]-nums[i+1]+1);
                    nums[i]-=(nums[i]-nums[i+1]+1);
                }
                less = !less;
            }else{
                if(nums[i]<=nums[i+1]){
                    res+= (nums[i+1]-nums[i]+1);
                    nums[i+1]-=(nums[i+1]-nums[i]+1);
                }
                less = !less;
            }
        }
        for(const auto& n : nums){
            cout<<n<<" ";
        }
        cout<<endl;
        return res;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        bool less = true;
        return min(zigzag(nums, less), zigzag(nums, !less));
    }
};
