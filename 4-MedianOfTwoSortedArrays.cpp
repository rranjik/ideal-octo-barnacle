class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()){
            auto temp =nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        bool odd = (nums1.size()+nums2.size())%2==1;
        int X = nums1.size();
        int Y = nums2.size();
        int l = 0;
        int roughlyHalf = (X+Y)/2;
        int h = nums1.size();
        while(l<=h){
            int numberElementsInLeftOf1 = (l+h)/2;
            int numberElementsInLeftOf2 = (roughlyHalf-numberElementsInLeftOf1);
            //jcout<<"px = "<<numberElementsInLeftOf1<<"; py = "<<numberElementsInLeftOf2<<endl;
            
            int xl = numberElementsInLeftOf1==0?numeric_limits<int>::min():nums1[numberElementsInLeftOf1-1];
            int xr = numberElementsInLeftOf1>=X?numeric_limits<int>::max():nums1[numberElementsInLeftOf1];
            
            
            int yl = numberElementsInLeftOf2==0?numeric_limits<int>::min():nums2[numberElementsInLeftOf2-1];
            int yr = numberElementsInLeftOf2>=Y?numeric_limits<int>::max():nums2[numberElementsInLeftOf2];
            //cout<<"xl = "<<xl<<"; xr = "<<xr<<"; yl = "<<yl<<"; yr = "<<yr<<endl;
            if(xl<=yr&&yl<=xr){
                if(odd){
                    return min(xr, yr);
                }
                else {
                    return (max(xl, yl)+min(yr, xr))/2.0;
                }
            }
            else if(xl>yr){
                h=numberElementsInLeftOf1-1;
            }
            else l = numberElementsInLeftOf1+1;
        }
        return -1;
    }
};
