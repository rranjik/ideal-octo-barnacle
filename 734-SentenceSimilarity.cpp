class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size()!=words2.size()) return false;
        if(!words1.size()) return true;
        unordered_map<string, set<string>> sim;
        for(const auto& p : pairs){
            sim[p[0]].insert(p[1]);
            sim[p[1]].insert(p[0]);
        }
        for(int i = 0; i<words1.size(); i++){
            if(words1[i]!=words2[i]){
                if(sim[words1[i]].find(words2[i])==sim[words1[i]].end()) return false;
            }
        }
        return true;
    }
};
