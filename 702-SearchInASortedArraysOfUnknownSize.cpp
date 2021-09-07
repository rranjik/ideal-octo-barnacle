/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int r = 1e4;
        int l = 0;
        int s = (1l<<31)-1;
        while(l<=r){
            int m = l+(r-l)/2;
            cout<<"l = "<<l<<" r = "<<r<<" m = "<<m<<endl;
            auto v = reader.get(m);
            cout<<"v = "<<v<<endl;;
            if(v==target) return m;
            if(v==s){
                r = m-1;
            }else if(v<target){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return -1;
    }
};
