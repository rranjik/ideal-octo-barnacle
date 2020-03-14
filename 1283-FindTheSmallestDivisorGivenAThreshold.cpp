class Solution {
    vector<int> nums;
public:
    int div(int divisor){
        int res = 0;
        for(auto const& n:nums){
            if(n%divisor){
                res+=((n/divisor)+1);
            } else {
                res+=(n/divisor);
            }
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        this->nums = nums;
        //int sum = 0;
        //for(auto const& n :nums){
        //    sum+=n;
        //}
        //cout<<"sum = "<<sum<<endl;
        
        int l = 1;
        int h = numeric_limits<int>::max();
        int res = numeric_limits<int>::max();
        while(l<=h){
            cout<<"l = "<<l<<"; h = "<<h<<endl;
            int m = (h-l)/2 + l;
            int r = div(m);
            cout<<"result of div by "<<m<<" is "<< r<<endl;
            if(r==threshold){
                res = min(res, m);
                h = m-1;
                cout<<"setting res to "<<res<<endl;
            } else if(r>threshold) {
                l = m+1;
            } else {
                h = m-1;
                res = min(res, m);
                cout<<"setting res to "<<res<<endl;
            }
        }
        return res;
    }
};
