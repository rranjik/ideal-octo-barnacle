class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ps(n+1);
        for(int i = 0; i<n; i++){
            ps[i+1] = ps[i]+nums[i];
        }
        //for(const auto& a : ps) cout<<a<<" "; cout<<endl;
        vector<int> res(n, -1);
        if(2*k>=n) return res;
        for(int i = 2*k; i<n; i++){
            auto l = i-k;
            auto sum = ps[i+1]-ps[i-2*k];
            res[l] = sum/(2*k+1);
        }
        return res;
    }
};
