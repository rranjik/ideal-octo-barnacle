class Solution {
public:
    int smallestRangeI(vector<int>& A, int k) {
        int small = *min_element(A.begin(), A.end());
        int large = *max_element(A.begin(), A.end());
        if((small+k)>(large-k)) return 0;
        return (large-k)-(small+k);
    }
};
