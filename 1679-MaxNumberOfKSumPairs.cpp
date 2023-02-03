class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = {0};
        unordered_map<int, int> f;
        for(const auto& n : nums){
            f[n]++;
        }
        for(auto& it : f){
            auto n = it.first;
            auto t = k-n;
            if(t!=n&&f.find(t)!=f.end()){
            auto rem=min(it.second, f[t]);
                res+=rem;
                it.second-=rem;
                f[t]-=rem;
            }else if(t==n){
                res+=(f[n]/2);
            }
        }
        return res;
    }
};
