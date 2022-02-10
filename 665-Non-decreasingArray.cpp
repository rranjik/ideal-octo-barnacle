class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int fvi = -1;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                if(fvi!=-1)
                    return false;
                fvi = i;
            }
        }
        cout<<"fvi = "<<fvi<<endl;
        return (fvi==-1||fvi==0||fvi==nums.size()-2||nums[fvi-1]<=nums[fvi+1]||nums[fvi]<=nums[fvi+2]);
    }
};
