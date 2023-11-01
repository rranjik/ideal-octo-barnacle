class Solution {
public:
    int minCost(vector<int>& s, vector<int>& h, vector<int>& rowCosts, vector<int>& colCosts) {
        int res = 0;
        //Row Direction
        int rd = s[0]<h[0] ? 1: -1;
        //Column Direction
        int cd = s[1]<h[1] ? 1: -1;
        for(int r = s[0]; r!= h[0]; r+= rd)
            res += rowCosts[r+rd];
        for(int c = s[1]; c!= h[1]; c+= cd)
            res += colCosts[c+cd];
        return res;
    }
};
