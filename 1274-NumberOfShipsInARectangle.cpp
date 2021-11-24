/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> tr/*topRight*/, vector<int> bl/*bottomLeft*/) {
        if(tr==bl) return sea.hasShips(tr, bl)?1:0;
        if(!sea.hasShips(tr, bl)) return 0;
        auto x1 = tr[0], y1 = tr[1], x2 = bl[0], y2 = bl[1];
        if(x1!=x2){
            return countShips(sea, {(x1+x2)/2, y1}, bl)+countShips(sea, tr, {(x1+x2)/2+1, y2});
        }
        return countShips(sea, {x1, (y1+y2)/2}, bl) + countShips(sea, tr, {x2, (y1+y2)/2+1});
    }
};
