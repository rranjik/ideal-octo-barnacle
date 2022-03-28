class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set c(candies.begin(), candies.end());
        return min(candies.size()/2, c.size());
    }
};
