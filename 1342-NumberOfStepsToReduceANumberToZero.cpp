class Solution {
public:
    int numberOfSteps (int num) {
        if(num==0) return 0;
        int res = 0;
        while(num){
            if(num%2) {
                num-=1;
                res++;
            }else {
                num/=2;
                res++;
            }
        }
        return res;
    }
};
