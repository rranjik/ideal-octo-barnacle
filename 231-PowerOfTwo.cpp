class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>1){
            if(n%2==0) n/=2;
            else return false;
        }
        return (n==1);
    }
};
