class Solution {
public:
    void dfs(vector<string> w, int i, set<string>& res){
        if(i==w.size()) {
            string r;
            for(const auto& e : w) r+=e, r+=" ";
            r.pop_back();
            res.insert(r);
            return;
        }
        dfs(w, i+1, res);
        for(const auto& s : adjl[w[i]]){
            auto temp = w[i];
            w[i] = s;
            dfs(w, i+1, res);
        }
    }
    map<string, set<string>> adjl;
    vector<string> generateSentences(vector<vector<string>>& synonyms, 
                                     string text) {
        map<string, string> inv; //dict -> scentence
        vector<string> words;
        int last_pos = 0;
        int pos = 0;
        while((pos = text.find(' ', last_pos))!=string::npos){
            string word = text.substr(last_pos, pos-last_pos);
            cout<<word<<endl;
            words.push_back(word);
            last_pos = pos+1;
        }
        string lastword = text.substr(last_pos, string::npos);
        words.push_back(lastword);
        for(const auto& w : words){
            cout<<w<<",";
        }
        unordered_set<string> t(words.begin(), words.end());
        for(int i = 0; i<synonyms.size(); i++){
            if(t.find(synonyms[i][0])!=t.end()) {
                adjl[synonyms[i][0]].insert(synonyms[i][1]);
                inv[synonyms[i][1]] = synonyms[i][0];
            }
            if(t.find(synonyms[i][1])!=t.end()) {
                adjl[synonyms[i][1]].insert(synonyms[i][0]);
                inv[synonyms[i][0]] = synonyms[i][1];
            }
            if(inv.find(synonyms[i][0])!=inv.end()){
                adjl[inv[synonyms[i][0]]].insert(synonyms[i][1]);
            }
            if(inv.find(synonyms[i][1])!=inv.end()){
                adjl[inv[synonyms[i][1]]].insert(synonyms[i][0]);
            }
        }
        cout<<endl;
        set<string> res;
        dfs(words, 0, res);
        vector<string> rres;
        for(const auto& s : res) rres.push_back(s);
        return rres;
    }
};
