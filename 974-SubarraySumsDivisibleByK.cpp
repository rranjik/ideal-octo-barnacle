class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        vector<int> ps(k);
        ps[0] = 1;
        int sum{};
        int res{};
        for(const auto& a : A){
            sum+=a;
            sum%=k;
            //might be negative 
            sum+=k;
            sum%=k;
            
            //everything that's also sum mod k wil be divisible by k
            //example for 5 a prefix sum of 7 and 2 is a pair
            //so is 13 and 18, and 19 and 59 etc
            
            res+=ps[sum];
            ps[sum]++;
        }
        return res;
    }
};
