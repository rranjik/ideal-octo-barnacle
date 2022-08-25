class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        char last{};
        pair<int, int> p({-1, -1});
        vector<vector<int>> res;
        for(int i= 0; i<s.length(); i++){
            auto c = s[i];
            if(c!=last){
                p.second = i-1;
                if(p.second-p.first+1>=3){
                    res.push_back({p.first, p.second});
                }
                p.first = i;
                last = c;
            }else p.second = i;
        }
        if(p.second-p.first+1>=3){
            res.push_back({p.first, p.second});
        }
        return res;
    }
};
