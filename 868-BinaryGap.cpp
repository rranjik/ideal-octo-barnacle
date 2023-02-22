class Solution {
public:
    int binaryGap(int n) {
        bitset<32> b(n);
        int res{};
        int l = -1;
        for(int i = 0; i<32; i++){
            if(b[i]){
                if(l==-1){
                    l = i;
                }else {
                    res = max(res, i-l);
                    l = i;
                }
            }
        }
        return res;
    }
};
