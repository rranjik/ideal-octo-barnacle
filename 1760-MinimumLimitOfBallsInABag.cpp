class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int l = 1; 
        int r = 1e9;
        while(l<r){
            cout<<"l = "<<l<<" r = "<<r<<endl;
            int m = (l+r)/2; int ops = 0;
            for(const auto& a : nums){
                //ops+=(a-1)/m;
                if(!(a%m)){
                    ops += (a/m-1);
                }else{
                    ops += (a/m);
                }
            }
            if(ops>k) l = m+1;
            else r = m;
        }
        return l;
    }
};
