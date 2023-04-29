class Solution {
public:
    int trailingZeroes(int n) {
        int res{};
        //remember that we need the number of 5's 
        //even numbers (factors of 2) overwhelm 5's
        //dividing by 5 gives the number of 5's in n (added as such)
        //dividing by 25 gives the number of 25's 
        //dividing by 625 gives the number of 625's 
        //...
        //n/25 = (n/5)/5 divide by 5 over and over again
        while(n!=0){
            res += n/5;
            n = n/5;
        }
        return res;
    }
};
