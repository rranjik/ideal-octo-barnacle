/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int bsearch(BinaryMatrix& bim, int r, int n){
        int lo = 0; int hi = n-1;
        int res = -1;
        while(lo<=hi){
            auto m = (lo+hi)/2;
            if(bim.get(r, m)==1){
                res = m;
                hi = m-1;
            }else{
                lo = m+1;
            }
        }
        return res==-1?n:res;
    }
    int leftMostColumnWithOne(BinaryMatrix &bim) {
       auto v = bim.dimensions();
       auto m = v[0]; auto n = v[1]; 
       int res = n;
       for(int i = 0; i<m; i++){
           auto f = bsearch(bim, i, n);
           res = min(res, f); 
       }
       return res==n?-1:res;
    }
};
