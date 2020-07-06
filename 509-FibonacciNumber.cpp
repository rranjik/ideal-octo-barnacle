class Solution {
public:
    int fib(int N) {
        if(N==0) return 0;
        if(N==1) return 1;
        int f1 = 1;
        int f2 = 0;
        int f3 = 0;
        for(int i = 2; i<=N; i++){
            f3 = f1 + f2;
            f2 = f1;
            f1 = f3;
        }
        return f3;
    }
};
