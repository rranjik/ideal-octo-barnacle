class Solution {
public:
    double minimumAverage(vector<int>& a) {
        sort(a.begin(), a.end());
        double res = 1e9;
        int j = a.size()-1;
        for(int i=0; i<a.size()/2;i++){
            res = min(res, (a[i]*1.0+a[j])/2);
            j--;
        }
        return res;
    }
};
