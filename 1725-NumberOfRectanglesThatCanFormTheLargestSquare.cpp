class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int, int> m;
        for(const auto& r : rectangles){
            auto s = min(r[0], r[1]);
            m[s]++;
        }
        auto it = m.rbegin();
        return it->second;
    }
};
