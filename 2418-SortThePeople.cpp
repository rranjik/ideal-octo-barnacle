class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> p;
        for(int i = 0; i<names.size(); i++){
            p.push_back({heights[i], names[i]});
        }
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        vector<string> res;
        for(int i = 0; i<names.size(); i++){
            res.push_back(p[i].second);
        }
        return res;
    }
};
