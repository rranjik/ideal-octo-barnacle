class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto g = *max_element(begin(candies), end(candies));
        vector<bool> res;
        for(const auto& k : candies){
            if(k+extraCandies>=g) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
