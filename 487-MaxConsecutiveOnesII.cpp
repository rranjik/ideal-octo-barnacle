class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int nz = 0;
        int i = 0;
        int j = 0;
        int res = 0;
        while(j<nums.size()){
            cout<<"i = "<<i<<" j = "<<j<<endl;
            if(nums[j]==0){
                nz++;
            }
            while(nz>1){
                if(i<=j&&i<nums.size()&&nums[i]==0){
                    nz--;
                }
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
