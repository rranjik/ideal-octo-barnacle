// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        while(l<=r){
            int mg = (l+(r-l)/2);
            auto res = guess(mg);
            if(!res)
                return mg;
            else if(res<0){
                r=mg-1;
            }
            else l = mg+1;
        }
        return n;
    }
};
