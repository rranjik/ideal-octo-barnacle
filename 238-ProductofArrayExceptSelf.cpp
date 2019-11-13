class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> f(nums.size(), 1);
        vector<int> b(nums.size(), 1);
        vector<int> res(nums.size(), 1);
        for(int i = 1; i<nums.size(); i++){
            b[i]=b[i-1]*nums[i-1];
        }
        cout<<"done b"<<endl;
        for(int i = nums.size()-2; i>=0; i--){
            f[i]=f[i+1]*nums[i+1];
        }
        cout<<"done f"<<endl;
        for(int i = 0; i<nums.size(); i++){
            res[i] = f[i]*b[i];
        }
        cout<<"done res"<<endl;
        return res;
    }
};
