class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num>1){
            int r = num%4;
            if(r) return false;
            num = num/4;
        }
        if(num==1) return true;
        return false;
    }
};
