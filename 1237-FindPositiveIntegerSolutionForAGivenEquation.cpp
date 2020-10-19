/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int x = 1000;
        int y = 1;
        while(y<1000){
            while(x>1&&customfunction.f(x, y)>z) x--;
            if(customfunction.f(x, y)==z&&x>=1&&y<=1000) 
            {res.push_back({x, y}); x--;}
            y++;
        }
        return res;
    }
};
