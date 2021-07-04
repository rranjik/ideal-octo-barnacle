class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res{};
        for(int i = 0; i<32; i++){
            cout<<"looking@ "<<i<<" ";
            cout<<"setting "<<31-i<<" ";
            uint32_t m = (n&(1<<i));
            m>>=i;
            m<<=31-i;
            cout<<"m = "<<bitset<32>(m)<<" res = "<<bitset<32>(res)<<endl;
            res = res|m;
        }
        return res;
    }
};
