class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        int on = num;
        while(num){
            int d = num%10;
            if(d)
                res += ((on%d==0)?1:0);
            num/=10;
        }
        return res;
    }
};
