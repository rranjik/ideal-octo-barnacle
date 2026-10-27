class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> m;
        while(n){
            int d = n%10;
            m[d]++;
            n/=10;
        }
        int res = 0;
        for(const auto& [k, v]: m){
            res += (k*v);
        }
        return res;
    }
};
