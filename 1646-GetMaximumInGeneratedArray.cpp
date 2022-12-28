class Solution {
public:
    int getMaximumGenerated(int n) {
        if(!n) return 0;
        vector<int> a(n+1);
        a[1] = 1;
        int res = 1;
        for(int i = 2; i<=n; i++){
            if(i%2){
                a[i] = a[i/2] + a[i/2+1];
                res = max(res, a[i]);
            }else {
                a[i] = a[i/2];
                res = max(res, a[i]);
            }
        }
        return res;
    }
};
