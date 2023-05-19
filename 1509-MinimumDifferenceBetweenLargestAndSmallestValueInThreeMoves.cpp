class Solution {
public:
    int minDifference(vector<int>& a) {
        if(a.size()<=4) return 0;
        auto n = a.size();
        sort(a.begin(), a.end());
        return min({a[n-1]-a[3], a[n-2]-a[2], a[n-3]-a[1], a[n-4]-a[0]});
    }
};
