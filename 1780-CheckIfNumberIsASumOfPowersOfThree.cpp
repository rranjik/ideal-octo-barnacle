class Solution {
public:
    bool checkPowersOfThree(int n) {
        string ternary;
        while(n){
            auto q = n/3;
            auto r = n%3;
            if(r==2) return false;
            n = q;
        }
        return true;
    }
};
