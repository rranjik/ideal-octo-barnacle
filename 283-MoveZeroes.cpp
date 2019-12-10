class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int nnz = 0;
        while(i<nums.size()){
            if(nums[i]!=0){
                nums[nnz] = nums[i];
                nnz++;
                i++;
            }   
            else 
                i++;
        }
        cout<<"i = "<<i<<"; j = "<<nnz<<endl;
        while(nnz<nums.size()){
            nums[nnz] = 0;
            nnz++;
        }
    }
};
