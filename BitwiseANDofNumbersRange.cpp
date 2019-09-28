class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = numeric_limits<int>::max();
        int c = 1;
        c <<= 31;
        int res = 0;
        if(m==n){
            return m;
        }
        while(c){
            int ml = m&c;
            int nl = n&c;
            if(ml!=nl)
                break;
            res |= nl;
            c>>=1;
        }
        return res;
    }
};
