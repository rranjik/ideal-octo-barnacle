class Solution {
public:
    int maxSubArray(vector<int>& a) {
        if(a.size()==0) return 0;
        if(a.size()==1) return a[0];
        vector<int> ps = a;
        for(int i = 1; i<a.size(); i++){
            ps[i] = ps[i]+ps[i-1];
        }
        int prevmin = 0;
        int res = ps[0]-prevmin;
        for(int i = 1; i<a.size(); i++){
            prevmin = min(prevmin, ps[i-1]);
            res = max(res, ps[i]-prevmin);
        }
        return res;
    }
};
