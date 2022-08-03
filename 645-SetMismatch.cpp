class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        for(int i = 0; i<nums.size(); i++){
            //cout<<"nums["<<i<<"] = "<<nums[i]<<endl;
            if(nums[abs(nums[i])-1]<0){
                res[0] = abs(nums[i]);
            }
            auto j = abs(nums[i]);
            nums[j-1] = -1*(abs(nums[j-1]));
        }
        //for(const auto& n : nums) cout<<n<<" "; cout<<endl;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0) {
                res[1] = i+1;
                break;
            }
        }
        return res;
    }
};
