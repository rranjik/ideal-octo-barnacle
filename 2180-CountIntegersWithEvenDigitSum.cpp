class Solution {
public:
    int ds(int n){
        int res = 0;
        while(n){
            res += (n%10);
            n/=10;
        }
        return res;
    }
    int countEven(int num) {
        int res = 0;
        for(int i = 2; i<=num; i++){
            if(ds(i)%2==0) res++;
        }
        return res;
    }
};
