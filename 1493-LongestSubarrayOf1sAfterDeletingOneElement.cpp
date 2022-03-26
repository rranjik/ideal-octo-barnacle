class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int res = 0;
        int nz{};
        for(int j = 0; j<nums.size(); j++){
            if(!nums[j]){
                while(nz>=1&&i<nums.size()){
                    if(!nums[i]) nz--;
                    i++;
                }
                nz++;
            }
            res = max(res, j-i);
            //if(nz) 
            //else res = max(res, j-i);
            //cout<<"j = "<<j<<" i = "<<i<<" res = "<<res<<endl;
        }
        return res;
    }
};
