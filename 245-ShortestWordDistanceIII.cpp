class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> m;
        for(int i = 0; i<wordsDict.size(); i++){
            m[wordsDict[i]].push_back(i);
        }
        if(word1==word2){
            auto w = m[word1];
            int res = 1e9;
            for(int i = 0; i<w.size()-1; i++){
                res = min(res, w[i+1]-w[i]);
            }
            return res;
        }
        
        auto w1 = m[word1];
        auto w2 = m[word2];
        if(w1[w1.size()-1]<w2[0]){
            return w2[0]-w1[w1.size()-1];
        }
        if(w2[w2.size()-1]<w1[0]){
            return w1[0]-w2[w2.size()-1];
        }
        int res = 1e9;
        for(const auto& i : w1){
            auto l2i = upper_bound(w2.begin(), w2.end(), i);
            if(l2i==w2.end()) continue;
            auto l2 = *l2i;
            res = min(res, abs(l2-i));
        }
        for(const auto& i : w2){
            auto l1i = upper_bound(w1.begin(), w1.end(), i);
            if(l1i==w1.end()) continue;
            auto l1 = *l1i;
            res = min(res, abs(l1-i));
        }
        return res;
    }
};
