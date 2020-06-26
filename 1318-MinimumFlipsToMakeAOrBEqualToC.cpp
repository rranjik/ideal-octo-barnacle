class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> x(a);
        bitset<32> y(b);
        bitset<32> z(c);
        bitset<32> ac = x|y;
        int res = 0;
        for(int i = 0; i<32; i++){
            if(z[i]!=ac[i]){
                if(z[i]){
                    res++;
                }else{
                    if(x[i]&&y[i]) res+=2;
                    else res++;
                }
            }
        }
        return res;
    }
};
