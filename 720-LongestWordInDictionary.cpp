class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> d(words.begin(), words.end());
        sort(begin(words), end(words), [](const string& a, const string& b){if(a.length()==b.length()) return a<b; else return a.length()>b.length();});
        for(int i = 0; i<words.size(); i++){
            auto res = true;
            for(int j = 0; j<words[i].length()&&res; j++){
                auto sub = words[i].substr(0, j+1);
                cout<<sub<<endl;
                res&=(d.find(sub)!=d.end());
            }
            if(res) return words[i];
        }
        return "";
    }
};
