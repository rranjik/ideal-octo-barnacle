class Solution {
public:
    
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for(int i = L; i<=R; i++){
            res+=((665772>>bitset<32>(i).count())&1);
        }
        return res;
    }
};
