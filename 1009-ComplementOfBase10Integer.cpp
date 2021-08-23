class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N) return 1;
        bitset<32> b(N);
        b=~b;
        for(int i =31; i>=0&&b[i]; i--){
            b[i] = 0;
        }
        return ((int)b.to_ulong());
    }
};
