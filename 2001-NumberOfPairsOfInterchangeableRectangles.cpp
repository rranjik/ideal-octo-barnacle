class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, unordered_map<int, int>> m;
        long long res = 0;
        for(const auto& r : rectangles){
            auto g = gcd(r[0], r[1]);
            auto n = r[0]/g;
            auto d = r[1]/g;
            if(m.find(n)!=m.end()&&m[n].find(d)!=m[n].end()){
                res+=m[n][d];
            }
            m[n][d]++;
        }
        return res;
    }
};
