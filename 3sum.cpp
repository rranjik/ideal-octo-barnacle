class Solution {
    bool binary_search(const vector<int>& nums, const int n){
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int c = (l+r)/2;
            cout<<"l = "<<l<<"; r = "<<r<<"; c = "<<c<<endl;
            cout<<"nums[c] = "<<nums[c]<<endl; 
            if(nums[c]==n)
                return true;
            else if(nums[c]>n)
                r=c-1;
            else if(nums[c]<n)
                l=c+1;
        }
        return false;
    }
        
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> a = {2 ,3, 4, 5, 6, 7};
        cout<<"binary_search(a,4) = "<<binary_search(a,4)<<endl;
        cout<<"binary_search(a,8) = "<<binary_search(a,8)<<endl;
        cout<<"binary_search(a,2) = "<<binary_search(a,2)<<endl;
        cout<<"binary_search(a,7) = "<<binary_search(a,7)<<endl;
        
        vector<int> b = {2};
        cout<<"binary_search(b,2) = "<<binary_search(b,2)<<endl;
        
        vector<int> c = {};
        cout<<"binary_search(c,1) = "<<binary_search(c,1)<<endl;
        
        vector<int> d = {2, 3};
        cout<<"binary_search(d,2) = "<<binary_search(d,2)<<endl;
        cout<<"binary_search(d,3) = "<<binary_search(d,3)<<endl;
        cout<<"binary_search(d,0) = "<<binary_search(d,0)<<endl;
        return vector<vector<int>>();
    }
};
