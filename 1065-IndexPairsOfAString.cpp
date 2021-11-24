class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        if(!text.length()) return res;
        for(const auto& w : words){
            int pos = 0;
            int from = 0;
            while((pos=text.find(w, from))!=string::npos){
                res.push_back({pos, pos+((int)w.length())-1});
                from = pos+1;
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};
