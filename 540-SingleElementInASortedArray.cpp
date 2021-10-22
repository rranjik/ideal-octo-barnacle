class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if(!nums.size()) return -1;
        if(nums.size()==1) return nums[0];
        while(l<=r){
            int m = l+(r-l)/2;
            cout<<"l = "<<l<<"; r = "<<r<<"; m = "<<m<<endl;
            //element
            int e = nums[m];
            if(m==nums.size()-1){
                cout<<"last element"<<endl;
                //previous element
                int pe = nums[m-1];
                //last element should have its 
                //pair before it 
                if(pe!=e) {
                    cout<<"last element does not match its previous element"<<endl;
                    return e;
                }
                else 
                    r = m-1;
            }else if (m==0){
                cout<<"first element"<<endl;
                //next element
                int ne = nums[m+1];
                //first element should have its
                //pair after it
                if(ne!=e) return nums[m];
                else 
                    l = m+1;
            }else{
                int ne = nums[m+1];
                int pe = nums[m-1];
                if(e!=ne&&e!=pe) return e;
                else if(e==ne&&m%2) r = m-1;
                else if(e==ne&&!(m%2)) l = m+1;
                else if(e==pe&&m%2) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};
