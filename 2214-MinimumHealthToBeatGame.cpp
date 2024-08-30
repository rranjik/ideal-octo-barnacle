class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long res = 1;
        int m = -1;
        for(const auto& d : damage){
            res+=d;
            m = max(m, d);
        }
        return res - min(m, armor);
    }
};
