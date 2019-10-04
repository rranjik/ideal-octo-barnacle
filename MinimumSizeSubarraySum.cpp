class Solution {
public:
    int minSubArrayLen(const int s, const vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int res = nums.size()+1;
        while(j<nums.size()){
            cout<<"i = "<<i<<"; j = "<<j << "; sum = "<<sum<<endl;
            while(sum<s && j<nums.size()){
                sum+=nums[j];
                j++;
            }
            while(sum>=s){
                res = min(res, j-i);
                sum-=nums[i];
                i++;
            }
        }
        if(res == nums.size()+1){
            return 0;
        }
        else 
            return res;
    }
};
