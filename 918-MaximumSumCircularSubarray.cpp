class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total{};
        int currMax = -1e9;
        int currMin = 1e9;
        int maxSum = -1e9;
        int minSum = 1e9;
        for(const auto& a : A){
            currMax = max(currMax+a, a);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin+a, a);
            minSum = min(minSum, currMin);
            total+=a;
        }
        return maxSum > 0 ? max(maxSum, total-minSum) : maxSum;
    }
};
