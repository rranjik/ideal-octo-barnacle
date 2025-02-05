class Solution {
public:
    void print(const vector<int>& v){
        for(const auto& x : v) cout<<x<<" "; cout<<endl;
    }
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dec(n, 1);
        vector<int> inc(n, 1);
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<=nums[i-1]){
                dec[i] = dec[i-1]+1;
            }
        }
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i]<=nums[i+1]){
                inc[i] = inc[i+1]+1;
            }
        }
        //print(dec);
        //print(inc);
        vector<int> res;
        for(int i = 1; i<nums.size()-1; i++){
            if(dec[i-1]>=k&&inc[i+1]>=k){
                res.push_back(i);
            }
        }
        return res;
    }
};
