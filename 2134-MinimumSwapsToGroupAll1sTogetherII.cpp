class Solution {
public:
    int group(vector<int>& a, int g, int k){
        int res = 1e9;
        int j = 0;
        int other = 0;
        for(int i = 0; i<a.size(); i++){
            if(i-j+1<=k){
                if(a[i]!=g){
                    other++;
                }
            }else{
                if(a[j]!=g){
                    other--;
                }
                
                if(a[i]!=g){
                    other++;
                }
                res = min(res, other);
                j++;
            }
            //cout<<"i = "<<i<<" j = "<<j<<" other = "<<other<<endl;
        }
        res = min(res, other);
        //cout<<"****"<<endl;
        return res;
    }
    int minSwaps(vector<int>& nums) {
        int w = 0;
        int z = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==1) w++;
            else z++;
        }
        //cout<<group(nums, 1, w)<<" "<<group(nums, 0, z)<<endl;
        return min(group(nums, 1, w), group(nums, 0, z));
        return 0;
    }
};
