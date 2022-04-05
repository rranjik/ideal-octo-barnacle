class Solution {
public:
    int numSub(string s) {
        int i = 0;
        unsigned long long res{};
        int m = 1e9+7;
        for(int j = 0; j<s.length(); j++){
            if(s[j]=='0'){
                long long d = j-i;
                d%=m;
                auto dp = (d+1)%m;
                long long add = (d*dp)/2;
                res+=add;
                res%=m;
                i = j+1;
            }
        }
        long long d = s.length()-i;
        d%=m;
        auto dp = (d+1)%m;
        long long add = (d*dp)/2;
        res+=add;
        res%=m;
        return res;
    }
};
