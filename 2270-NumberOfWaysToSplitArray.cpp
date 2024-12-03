class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> ps;
        long long run = 0;
        for(const auto& n : nums){
            ps.push_back(n+run);
            run+=n;
        }
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            auto before = ps[i];
            auto after = run-before;
            res+=(i<nums.size()-1&&before>=after?1:0);
        }
        return res;
    }
};
