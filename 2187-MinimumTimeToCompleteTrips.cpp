class Solution {
public:
    long long minimumTime(vector<int>& t, int tt) {
        sort(t.begin(), t.end());
        int n = t.size();
        long long ttt = tt;
        long long r = t[n-1]*ttt;
        long long l = 1;
        while(l<r){
            auto m = (l+r)/2;
            long long x = 0;
            for(int i = 0; i<t.size(); i++){
                x+=(m/t[i]);
                if(x>=tt) break;
            }
            if(x>=tt){
                r = m;
            }else{
                l = m+1;
            }
        }
        return r;
    }
};
