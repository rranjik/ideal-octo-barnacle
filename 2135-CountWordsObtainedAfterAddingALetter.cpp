class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<string, int> s;
        for(auto& t : targetWords){
            sort(t.begin(), t.end());
            s[t]++;
        }
        int res = 0;
        for(auto& w : startWords){
            for(int i = 0; i<26; i++){
                char c = static_cast<char>('a'+i);
                if(w.find(c)==string::npos){
                    auto wp = w+c;
                    sort(wp.begin(), wp.end());
                    if(s.find(wp)!=s.end()) {
                        res += s[wp];
                        s.erase(wp);
                        //cout<<wp<<" can be obtained from "<<w<<endl;
                    }
                }
            }
        }
        return res;
    }
};
