class Solution {
public:
    double help(double x, long long n){
        if(n==0) return 1;
        if(n%2){
            return x*help(x*x, (n-1)/2);
        }else {
            return help(x*x, n/2);
        }
    }
    double myPow(double x, int n) {
        auto p = help(x, abs((long long)n));
        if(n<0) return 1/p;
        else return p;
    }
};
