class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n = a.size();
        int maxGain = numeric_limits<int>::min();
        int maxEndRight = a[n-1] - n-1;
        for(int i = n-2; i>=0; i--){
            maxEndRight = max(maxEndRight, a[i+1]-(i+1));
            maxGain = max(maxGain, a[i]+i+maxEndRight);
        }
        return maxGain;
    }
};
