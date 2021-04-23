class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long r = 0;
        long i = 0;
        long added = 0;
        while(r<n){
            if(i<nums.size()&&nums[i]<=r+1){
                cout<<"r+1 "<<r+1<<" i = "<<nums[i]<<endl;
                //refer notes for notation used
                //or a previous submission for notes in the comments 
                r += nums[i];
                i++;
            }else {
                cout<<"r+1 = "<<r+1<<endl;
                r=2*r+1;
                added++;
            }
        }
        return added;
    }
};
