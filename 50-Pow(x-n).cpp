class Solution {
public:
    unordered_map<int, double> c;
    double posPow(double x, int n){
        if(c.find(n)!=c.end()) return c[n];
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2) return c[n] = posPow(x, n/2)*posPow(x, n/2)*x;
        return c[n] = posPow(x, n/2)*posPow(x, n/2);
    }
    double myPow(double x, int n) {
        if(n<0) {
            //cout<<posPow(x, abs(n))<<endl;
            return 1.0/posPow(x, abs(n));
        }
        //cout<<posPow(x, n)<<endl;
        return posPow(x, n);
    }
};
