class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(abs(nums[i])<nums.size())
            nums[abs(nums[i])] = (abs(nums[abs(nums[i])])*-1);
            if(abs(nums[i])==nums.size())
            nums[0] = (abs(nums[0])*-1);
        }
        vector<int> mp;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0) mp.push_back(i);
            nums[i]*=-1;
        }
        for(const auto& n : mp){
            cout<<n<<" ";
        }
        cout<<endl;
        for(int i = 0; i<nums.size(); i++){
            if(abs(nums[i])<nums.size())
            nums[abs(nums[i])] = (nums[abs(nums[i])]*-1);
            if(abs(nums[i])==nums.size())
            nums[0] = (nums[0]*-1);
        }
        
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            if(i!=0&&nums[i]>0) res.push_back(i);
            if(!i&&nums[i]>0) res.push_back(nums.size());
        }
        return res;
    }
};
