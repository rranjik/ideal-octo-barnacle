class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        cout<<"nums.size() = "<<nums.size()<<" k = "<<k<<endl;
        int res = -1;
        if(k>nums.size()) {
            if(k%2&&nums.size()==1) return -1;
            return *max_element(nums.begin(), nums.end());
        }
        for(int i = 0; i<nums.size(); i++){
            if(k>=i){
                if(i!=k-1)
                    res = max(res, nums[i]);
            }
            //if(k%2&&i%2&&i<=k){
            //    res = max(res, nums[i]);
            //}else if (k%2==0&&i%2==0&&i<=k){
            //    res = max(res, nums[i]);
            //}
        }
        return res;
    }
};
