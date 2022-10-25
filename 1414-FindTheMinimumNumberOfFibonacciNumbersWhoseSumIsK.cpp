class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> b;
        int f1 = 1;
        int f2 = 1;
        b.push_back(f1);
        b.push_back(f2);
        int f3 = f1+f2;
        while(f3<=k){
            b.push_back(f3);
            f1 = f2;
            f2 = f3;
            f3 = f1+f2;
        }
        int n = b.size()-1;
        int res{};
        while(k){
            while(b[n]>k){
                n--;
            }
            while(k&&b[n]<=k){
                k-=b[n];
                res++;
            }
        }
        return res;
    }
};
