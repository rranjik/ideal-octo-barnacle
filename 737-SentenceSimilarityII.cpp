class Solution {
public:
    unordered_map<string, vector<string>> adjl;
    unordered_set<string> v;
    bool dfs(string c, const string& l){
        v.insert(c);
        if(c==l) return true;
        bool res = false;
        for(const auto& w : adjl[c]){
            if(v.find(w)==v.end()){
                res |=dfs(w, l);
            }
        }
        return res;
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size()!=words2.size()) return false;
        if(!words1.size()) return true;
        for(const auto& p : pairs){
            adjl[p[0]].push_back(p[1]);
            adjl[p[1]].push_back(p[0]);
        }
        int res = true;
        for(int i = 0; res&&i<words1.size(); i++){
            res&=dfs(words1[i], words2[i]);
            v.clear();
        }
        return res;
    }
};
