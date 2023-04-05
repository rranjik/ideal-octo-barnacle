class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastseen = nums[0];
        int freq = 1;
        int nexta = 1;
        for(int i = 1; i<nums.size(); i++){
            cout<<"i = "<<i<<" nexta = "<<nexta<<endl;
            if(nums[i]!=lastseen){
                nums[nexta] = nums[i];
                lastseen = nums[i];
                freq = 1;
                nexta++;
            }else{
                freq++;
                if(freq<=2){
                    nums[nexta] = nums[i];
                    nexta++;
                }
            }
        }
        return nexta;
    }
};
