class Solution {
public:
    string base7(int n){
        string res;
        while(n){
            int digit = n%7;
            res+=to_string(digit);
            n/=7;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string convertToBase7(int num) {
        if(!num) return "0";
        string res;
        if(num<0) res+="-";
        num = abs(num);
        auto r = base7(num);
        if(!r.length()) return 0;
        res+=r;
        return res;
    }
};
