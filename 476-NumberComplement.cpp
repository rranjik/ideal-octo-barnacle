class Solution {
public:
    int findComplement(int num) {
        bitset<32> b(num);
        b = ~b;
        for(int i = 31; i>=0&&b[i]; i--){
            b[i] = 0;
        }
        return (int)(b.to_ulong());
    }
};
