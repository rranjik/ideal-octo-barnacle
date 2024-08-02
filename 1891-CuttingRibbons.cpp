class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int r = 0;
        for(const auto& b : ribbons){
            r = max(b, r);
        }
        int l = 0;
        int mres = 0;
        int mlen = 0;
        while(l<=r){
            int m = (l+r)/2;
            cout<<"l = "<<l<<" r = "<<r<<" m = "<<m <<endl;
            if(!m) {
                l++; continue;
            };
            int res = 0;
            for(const auto& b : ribbons){
                res += (b/m);
            }
            cout<<"res = "<<res<<endl;
            if(res>=k){
                mlen = m;
                mres = res;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return mlen;
    }
};
