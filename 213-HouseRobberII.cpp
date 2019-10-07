class Solution {
public:
    unordered_map<int, int> cache;
    int dp(const int i, const vector<int>& nums){
        cout<<"i = "<<i<<endl;
        if(cache.find(i)!=cache.end()){
            return cache[i];
        }
        else{
            if(i>=nums.size()){
                cache[i] = 0;
            }
            else{
                cache[i] = max(dp(i+1, nums), dp(i+2, nums)+nums[i]);
            }
            return cache[i];
        }
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1)
            return nums[0];
        //for(const auto& a : vector<int>(nums.begin()+1, nums.end()))
        //    cout<<a<<" ";
        //cout<<endl;
        //for(const auto& a : vector<int>(nums.begin(), nums.end()-1))
        //    cout<<a<<" ";
        //cout<<endl;
        int leavefirst = dp(0, vector<int>(nums.begin()+1, nums.end()));
        cache.clear();
        int leavelast = dp(0, vector<int>(nums.begin(), nums.end()-1));
        return max(leavefirst, leavelast);
    }
};
