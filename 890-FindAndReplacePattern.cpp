class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> words, string p) {
        vector<string> res;
        auto norm = normalize(p);
        cout<<"norm = "<<norm<<endl;
        for (string w : words) {
            auto wnorm = normalize(w);
            cout<<w<<" wnorm = "<<wnorm<<endl;
            if (wnorm == norm) {
                res.push_back(w);
            }
        }
        return res;
    }

    string normalize(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) {
            m[c] = m.size();
        }
        for (int i = 0; i < w.length(); ++i) {
            w[i] = 'a' + m[w[i]];
        }
        return w;
    }
};
