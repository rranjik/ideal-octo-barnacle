class Solution {
public:
    int numWaterBottles(int full, int ex, int empty = 0) {
        if(!full) return 0;
        int drink{}; 
        drink += full;
        auto e = full + empty;
        int nfull = e/ex;
        drink += (numWaterBottles(nfull, ex, e%ex));
        return drink;
    }
};
