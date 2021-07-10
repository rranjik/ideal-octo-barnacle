class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        int sqrt2N = (int)(sqrt(2*N))+1;
        for(int k = 1; k<sqrt2N; k++){
            if((N-(k*(k-1))/2)%k==0) res++;
        }
        return res;
    }
};
