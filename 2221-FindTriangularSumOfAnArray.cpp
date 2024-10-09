class Solution {
public:
    void print(vector<int>& v){
        for(const auto& n : v) cout<<n<<" "; cout<<endl;
    }
    int triangularSum(vector<int>& nums) {
        for(int i = 0; i<nums.size()-1; i++){
            for(int j = 0; j<nums.size()-1; j++){
                nums[j] = (nums[j]+nums[j+1])%10;
            }
            //print(nums);
        }
        return nums[0];
    }
};
