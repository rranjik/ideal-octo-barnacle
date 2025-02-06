class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int msum = 0;
        int sum = 0;
        int n = arr.size();
        for(int i = 0; i<min(2, k)*n; i++){
            sum = max(sum+arr[i%n], arr[i%n]);
            msum = max(msum, sum);
        }

        int m = 1e9+7;
        msum%=m;
        return msum+
            max(0ll, accumulate(arr.begin(), arr.end(), 0ll)*max(0, k-2))%m;
    }
};
