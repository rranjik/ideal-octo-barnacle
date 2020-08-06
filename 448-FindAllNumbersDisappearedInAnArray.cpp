class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            int a = abs(nums[i]);
            int pos = a -1;
            if(pos<nums.size()&&nums[pos]>0)
                nums[pos] = -nums[pos];
            //for(const auto& n : nums){
            //    cout<<n<<" ";
            //}
            //cout<<endl;
        }
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0)res.push_back(i+1);
        }
        return res;
    }
};
