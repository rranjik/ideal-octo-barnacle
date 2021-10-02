class Solution {
public:
    vector<string> extract(string a){
        stringstream ss(a);
        string word;
        vector<string> res;
        while(ss>>word){
            res.push_back(word);
        }
        return res;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        auto a = extract(A);
        auto b = extract(B);
        unordered_map<string, int> fa;
        unordered_map<string, int> fb;
        for(const auto& w : a) fa[w]++;
        for(const auto& w : b) fb[w]++;
        vector<string> res;
        for(const auto& it : fa){
            if(it.second==1 && fb.find(it.first)==fb.end()) res.push_back(it.first);
        }
        for(const auto& it : fb){
            if(it.second==1 && fa.find(it.first)==fa.end()) res.push_back(it.first);
        }
        return res;
    }
};
