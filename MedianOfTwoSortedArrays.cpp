class Solution {
    size_t total;
    bool odd;
    double fm(const vector<int>& nums1, const vector<int>& nums2, size_t p){
        size_t ptib = (total/2) - p;
        cout<<"ptib "<<ptib<<endl;
        cout<<"p "<<p<<endl;
        int x1, x2, y1, y2;
        x1 = nums1[p];
        y1 = nums2[ptib];
        if(p==nums1.size()-1){
            x2 = numeric_limits<int>::max();
        }
        else{
            x2 = nums1[p+1];
        }
        if(ptib==nums2.size()-1){
            y2 = numeric_limits<int>::max();
        }
        else{
            y2 = nums2[ptib+1];
        }
        if(x1<= y2 && x2>=y1){
            if(odd){
                return max(x1, y1);
            }
            else{
                return (max(x1, y1), min(x2, y2))/2;
            }
        }
        else if(x1> y1){
            return fm(nums1, nums2, (0+p)/2);
        }
        else{
            return fm(nums1, nums2, (nums1.size()-p)/2);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        total = nums1.size()+nums2.size();
        cout<<"total "<<total<<endl;
        odd = ((nums1.size()+nums2.size())%2)==1;
        cout<<"odd "<<odd<<endl;
        if(nums1.size()==0){
            return 1;
            if(odd){
                return nums2[(nums2.size()-1)/2];
            }
            else{
                return (nums2[nums2.size()/2]+nums2[(nums2.size()+1)/2])/2;
            }
        }
        else if(nums2.size()==0){
            return 2;
            if(odd){
                return nums1[(nums1.size()-1)/2];
            }
            else{
                return (nums1[nums1.size()/2]+nums1[(nums1.size()+1)/2])/2;
            }
        }
        return fm(nums1, nums2, nums1.size()/2);
    }
};
