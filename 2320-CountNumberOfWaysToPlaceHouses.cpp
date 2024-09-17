class Solution {
public:
    int countHousePlacements(int n) {
        vector<int> te(n+1), tt(n+1), tb(n+1), tf(n+1);
        te[1]=tt[1]=tb[1]=tf[1]=1;
        int m = 1e9+7;
        for(int i = 2; i<=n; i++){
            te[i] = (((((tf[i-1]+tb[i-1])%m)+tt[i-1])%m)+te[i-1])%m;
            tf[i] = te[i-1]%m;
            tb[i] = (te[i-1]+tt[i-1])%m;
            tt[i] = (te[i-1]+tb[i-1])%m;
        }
        return (((te[n]+tt[n])%m+tb[n])%m+tf[n])%m;
    }
};
