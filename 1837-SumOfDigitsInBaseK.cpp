class Solution {
public:
    
    int sumBase(int n, int k) {
        int res{};
        while(n>=k){
            res+=n%k;
            n = n/k;
        }
        res+=n;
        return res;
    }
};
