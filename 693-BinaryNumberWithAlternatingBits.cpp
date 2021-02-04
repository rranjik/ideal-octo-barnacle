class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> b(n);
        cout<<b<<endl;
        int fo = -1;
        for(int i = 31; i>=0; i--){
            if(b[i]) {
                fo = i;
                break;
            }
        }
        if(fo==-1) return true;
        for(int j = fo; j>0; j--){
            if(!(b[j]^b[j-1])) return false;
        }
        return true;
    }
};
