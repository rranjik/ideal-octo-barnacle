class NumArray {
    vector<int> rs;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            rs.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if(i!=0){
            return rs[j]-rs[i-1];
        }
        else{
            return rs[j];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
