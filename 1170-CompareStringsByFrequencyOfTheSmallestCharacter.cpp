class Solution {
public:
    int f(string s){
        map<char, int> m;
        for(const auto& c : s) m[c]++;
        return m.begin()->second;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        unordered_map<string, int> fs;
        for(const auto& word : words) fs[word] = f(word);
        for(const auto& q : queries) fs[q] = f(q);
        auto cmp = [&](const string& a, const string& b){return fs[a]<fs[b];};
        multiset<string, decltype(cmp)> s(cmp);
        for(const auto& w : words) s.insert(w);
        for(const auto& w : s) cout<<w<<endl;
        if(s.size()!=fs.size()) cout<<"something's wrong "<<endl;
        vector<int> res;
        for(const auto& q : queries){
            res.push_back(distance(s.upper_bound(q), s.end()));
        }
        return res;
    }
};
