class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<long long, int> gcdm;
        long long res = 0;
        for(const auto& a : nums){
            long long gcda = gcd(a, k);
            for(const auto& [gcdb, count] : gcdm){
                if(gcdb*gcda%k==0)
                    res+=count;
            }
            gcdm[gcda]++;
        }
        return res;
    }
};
