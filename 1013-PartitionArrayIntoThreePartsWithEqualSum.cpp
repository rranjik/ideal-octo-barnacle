class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum{};
        for(const auto& a : A) sum+=a;
        if(sum%3) return false;
        auto target = sum/3;
        sum = 0;
        int p = 1;
        for(const auto& a : A){
            sum+=a;
            if(sum==(p*target)) p++;
        }
        return p>=4;
    }
};
