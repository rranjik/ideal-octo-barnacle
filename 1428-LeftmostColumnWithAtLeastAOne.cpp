/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int firstOneInRow(int row, int to, BinaryMatrix& b){
        if(to<n){
            auto valto = b.get(row, to);
            if(!valto) return to+1;
        }
        int left = 0;
        int right = to;
        while(left<=right){
            int mid = left+(right-left)/2;
            cout<<"left = "<<left<<"; right = "<<right<<" mid = "<<mid<<endl;
            auto val = b.get(row, mid);
            if(mid==n-1&&val) return mid;
            if(mid==n-1&&!val) return n+1;
            auto next = b.get(row, mid+1);
            if(mid==0&&!val&&next) return mid+1;
            if(mid==0&&val) return mid;
            if(!val&&next) return mid+1;
            if(val){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return n+1;
    }
    int m;
    int n;
    int leftMostColumnWithOne(BinaryMatrix &b) {
        auto dim = b.dimensions();
        m = dim[0]; n = dim[1];
        int res = n+1;
        for(int i = 0; i<m; i++){
            auto first1InRow = firstOneInRow(i, min(res, n-1), b);
            cout<<"first one in row = "<<i<<" is "<< first1InRow<<endl;
            res = min(res, first1InRow);
        }
        return res>=n?-1:res;
    }
};
