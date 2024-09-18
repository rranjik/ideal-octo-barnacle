class Solution {
public:
    int kadane(const vector<int>& a, const vector<int>& b){
        //lol reads "m Sumati"
        int msumati = 0;
        int n = a.size();
        int res = 0;
        for(int i = 0; i<n; i++){
            msumati = max(b[i]-a[i], msumati+(b[i]-a[i]));
            res = max(res, msumati);
        }
        return res;
    }
    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        return max(accumulate(a.begin(), a.end(), 0)+ kadane(a, b),
                accumulate(b.begin(), b.end(), 0)+ kadane(b, a));
    }
};
