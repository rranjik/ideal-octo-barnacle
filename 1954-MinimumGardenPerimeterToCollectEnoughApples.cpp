class Solution {
public:
    long long apples(long long n){
        if(n<=0) return 0;
        return (4*n*n*n)+(6*n*n)+(2*n);
    }
    long long minimumPerimeter(long long na) {
        long r = 100000;
        long l = 1;
        int res = 0;
        while (l<=r){
            auto m = ((l+r)%2?(l+r)/2+1:(l+r)/2);
            auto app = apples(m);
            cout<<"l = "<<l<<" r = "<<r<<" m = "<<m<<" app = "<<app<<endl;
            if(app>na){
                res = m;
                r = m-1;
            }else if(app<na){
                l = m+1;
            }else{
                return (8*m);
            }
        }
        return (8*res);
    }
};
