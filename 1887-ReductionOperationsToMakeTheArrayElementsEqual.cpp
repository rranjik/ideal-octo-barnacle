class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int l = -1;
        int grp = 0;
        int small = nums[nums.size()-1];
        cout<<"small = "<<small<<endl;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==small) return res+grp;
            if(l==nums[i]) grp++;
            else{
                res+=grp;
                grp++;
                l = nums[i];
            }
        }
        return res;
    }
};
